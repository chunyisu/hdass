/***************************************************************************
begin                : 2004/03/12
copyright            : (C) Mark Kretschmann
email                : markey@web.de
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "plugin.h"
#include "pluginmanager.h"

#include <assert.h>
#include <vector>

#include <qfile.h>
#include <qstring.h>

#include <kdebug.h>
#include <klibloader.h>

vector<PluginManager::StoreItem>
PluginManager::m_store;


/////////////////////////////////////////////////////////////////////////////////////
// PUBLIC INTERFACE
/////////////////////////////////////////////////////////////////////////////////////

KTrader::OfferList     
PluginManager::query( const QString& constraint )
{    
    // Add versioning constraint
    QString str = QString( "[X-KDE-amaroK-framework-version] >= %1 and " )
                     .arg( FrameworkVersion );
    
    kdDebug() << k_funcinfo << endl
              << "Plugin trader constraint: " << str + constraint << endl;
    
    return KTrader::self()->query( "amaroK/Plugin", str + constraint );
}    
    
    
Plugin*
PluginManager::createFromQuery( const QString& constraint )
{
    KTrader::OfferList offers = query( constraint );

    if ( offers.isEmpty() ) {
        kdWarning() << k_funcinfo << "No matching plugin found.\n";                                          
        return 0;
    }
                
    return createFromService( *offers.begin() );    
}

    
Plugin*
PluginManager::createFromService( const KService::Ptr service )
{
    kdDebug() << k_funcinfo << "Trying to load: " << service->library() << endl;
    
    //get the library loader instance
    KLibLoader *loader = KLibLoader::self();
    //try to load the specified library
    KLibrary *lib = loader->globalLibrary( QFile::encodeName( service->library() ) );

    if ( !lib ) {
        kdWarning() << k_funcinfo << "lib == NULL\n";
        return 0;
    }
    //look up address of init function and cast it to pointer-to-function
    Plugin* (*create_plugin)() = ( Plugin* (*)() ) lib->symbol( "create_plugin" );
    
    if ( !create_plugin ) {
        kdWarning() << k_funcinfo << "create_plugin == NULL\n";
        return 0;
    }
    //create plugin on the heap
    Plugin* plugin = create_plugin();
    
    //put plugin into store
    StoreItem item;
    item.plugin = plugin;
    item.library = lib;
    item.service = service;
    m_store.push_back( item );
    
    dump( service );
    return plugin;
}


void
PluginManager::unload( Plugin* plugin )
{
    kdDebug() << k_funcinfo << endl;
    
    vector<StoreItem>::iterator iter = lookupPlugin( plugin ); 
            
    if ( iter != m_store.end() ) {
        delete (*iter).plugin;
        kdDebug() << "Unloading library: "<< (*iter).service->library() << endl;
        (*iter).library->unload();
        
        m_store.erase( iter );
    }
    else
        kdWarning() << k_funcinfo << "Could not unload plugin (not found in store).\n";
}


KService::Ptr
PluginManager::getService( const Plugin* plugin )
{
    kdDebug() << k_funcinfo << endl;
    
    if ( !plugin ) {
        kdWarning() << k_funcinfo << "pointer == NULL\n";   
        return 0;
    }
       
    //search plugin in store
    vector<StoreItem>::const_iterator iter = lookupPlugin( plugin ); 
    
    if ( iter == m_store.end() ) 
        kdWarning() << k_funcinfo << "Plugin not found in store.\n";
    
    return (*iter).service;
}


void    
PluginManager::dump( const KService::Ptr service )
{
    assert( service.data() );
    
    kdDebug() << endl;
    
    kdDebug() << "PluginManager Service DUMP:\n";
    kdDebug() << "---------------------------\n";
    kdDebug() << "name                          : "
                << service->name()                                                  << endl;
    kdDebug() << "library                       : "
                << service->library()                                               << endl;
    kdDebug() << "desktopEntryPath              : "
                << service->desktopEntryPath()                                      << endl;
    kdDebug() << "X-KDE-plugintype              : "
                << service->property( "X-KDE-amaroK-plugintype" ).toString()        << endl;
    kdDebug() << "X-KDE-amaroK-authors          : "
                << service->property( "X-KDE-amaroK-authors" ).toStringList()       << endl;
    kdDebug() << "X-KDE-amaroK-version          : "
                << service->property( "X-KDE-amaroK-version" ).toString()           << endl;
    kdDebug() << "X-KDE-amaroK-framework-version: "
                << service->property( "X-KDE-amaroK-framework-version" ).toString() << endl;
    
    kdDebug() << endl;
}

    
/////////////////////////////////////////////////////////////////////////////////////
// PRIVATE INTERFACE
/////////////////////////////////////////////////////////////////////////////////////

vector<PluginManager::StoreItem>::iterator
PluginManager::lookupPlugin( const Plugin* plugin )
{
    vector<StoreItem>::iterator iter; 
    
    //search plugin pointer in store
    for ( iter = m_store.begin(); iter != m_store.end(); iter++ ) {
        if ( (*iter).plugin == plugin )
            break;
    }

    return iter;
}


