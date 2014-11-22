/***************************************************************************
 *   Copyright (C) 2004 by Karban                                          *
 *   Karban@scream01.csie.ncku.edu.tw                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "MyBrowser.h"

#include <qstring.h>

#include <kparts/browserextension.h> 
#include <kurl.h>
#include <kdebug.h>
#include "global_define.h"
MyBrowser::MyBrowser(QWidget *parentWidget)
: KHTMLPart(parentWidget)
{
    it_history = history.begin();
    home = KURL("http://tw.yahoo.com");
    #if TRACE 
    kdDebug() << "init() -> "<< home << endl;    
    #endif
    handleHome();      
}


MyBrowser::~MyBrowser()
{

}

void MyBrowser::urlSelected(const QString &url, int button, int state, const QString &_target, KParts::URLArgs args)
{
     KURL cURL = completeURL(url);
     #if TRACE 
kdDebug() << "urlSelect -> " << cURL << endl;     
#endif
     if(cURL.protocol()=="http")
     {
     	removeHistory();
     	openURL(cURL);
     	saveHistory(cURL);
     }
     else if(cURL.protocol()=="hdas")
     {
#if TRACE      
kdDebug()<< "MyBrowser::urlSelected -> HDAS -> " << cURL << endl;
#endif
     	getFile(cURL);
     }
}

void MyBrowser::saveHistory(const KURL &url)
{
#if TRACE 
kdDebug() << "Saving History !!"<< endl;
#endif
	history << url;      
    	++it_history;
}

void MyBrowser::removeHistory()
{
    if(it_history != history.end())
    {
    	KURL::List::Iterator it_remove = history.end();
	for(it_remove;it_remove!=it_history;it_remove--)history.remove((*it_remove).url());
    }
}

void MyBrowser::getFile(KURL &url)
{
#if TRACE 
kdDebug()<< "getFile -> download a mp3 file "<< endl;
#endif
    getfile = new DownFile(url);
    connect(getfile,SIGNAL(Finished(bool)),this,SLOT(handleCloseconnect(bool)));
}

//========SLOT==( Handle Serial )===================================

void MyBrowser::handleHome()
{
    if(home.protocol()=="http")
    {
    	openURL(home);
    	saveHistory(home);
    }	
    else kdDebug() << "=====================Home -> " << home.protocol() << endl;
}

void MyBrowser::handleNext()
{
#if TRACE 
kdDebug() << "handleNext"<< endl;
#endif
    if(it_history != history.end())
    {
    	++it_history;
    	openURL((*it_history).url());

    }   
}

void MyBrowser::handlePrevious()
{
#if TRACE 
kdDebug() << "handlePrevious"<< endl;
#endif
    if(it_history != history.begin())
    {
    	--it_history;
	openURL((*it_history).url());

    }	
}

void MyBrowser::handleRefresh()
{
#if TRACE 
kdDebug() << "handleRefresh"<< endl;
#endif    
    openURL((*it_history).url());
}

void MyBrowser::handleURL(const KURL &uurl,const KParts::URLArgs &args)
{
#if TRACE 
kdDebug() << "handleURL -> submit control"<< endl;
#endif
    if(uurl.protocol()=="http")
    {
    	removeHistory();
    	openURL(uurl);
    	saveHistory(uurl);
    }	
    else if(uurl.protocol()=="hdas")
    {    	
        KURL url = uurl;
       	getFile(url);
    }
}

void MyBrowser::handleCloseconnect(bool error)
{
    delete getfile;
    #if TRACE     
kdDebug() << "MyBrowser::handleCloseconnect -> Delete connection !!!!"<< endl;
#endif    
}
#include "MyBrowser.moc"

