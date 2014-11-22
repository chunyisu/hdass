/***************************************************************************
                        Myplayer.h  -  description
                            -------------------
    begin                : 7-19 2004
    copyright            : (C) 2004 by Karban
    email                :
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/
 
#include "Myplayer.h"
#include "enginecontroller.h"
#include "amarokconfig.h"
#include "artsengine.h"
#include "metabundle.h"

#include <kdebug.h>
#include <kurl.h>
#include <kapplication.h>

#include <qstring.h>
#include <qfile.h>

Myplayer::Myplayer()
{
     bool restartArts = false;
     m_repeat = true;
     m_random = false;
     EngineBase* const engine = new ArtsEngine();
     engine->init( restartArts, 9, true );//AmarokConfig::rememberEffects() );
     engine->initMixer( false );//AmarokConfig::hardwareMixer() ); try to check the hardware mixer and use it 
     engine->setVolume( 50 );
     m_Vol = 50;
     EngineController::setEngine( engine );
     engine->setSoundOutput( "Alsa" );
     engine->setSoundDevice( AmarokConfig::soundDevice() );
     engine->setDefaultSoundDevice( !AmarokConfig::customSoundDevice() );
     engine->setRestoreEffects( AmarokConfig::rememberEffects() );
         //TODO deprecate/improve
     engine->setXfadeLength( 2200 );
     EngineController* const ec = EngineController::instance();
     connect( ec, SIGNAL( orderNext() ), SLOT( handleNext() ) );
     connect( ec, SIGNAL( orderPrevious() ), SLOT( handlePrevious() ) );      
     connect(ec, SIGNAL(TrackPosition(int)), SLOT(handlePosition(int)) );
     it = m_list.begin();
}

Myplayer::~Myplayer()       
{
   kdDebug() << k_funcinfo << endl;
}

//==================Basic=Slot==================
void Myplayer::play()
{          
     if(!m_list.isEmpty())
     {
       MetaBundle bundle( (*it).url() );        
       EngineController::instance()->play(bundle); 
       handleMessage(bundle);
       kdDebug() << "[engine] play: " << endl;            
     }
     else
     {
        EngineController::instance()->stop();
        kdDebug() << "[engine] Stop: " << endl;            
     }
}
void Myplayer::play(QString filename)
{
   bool find=false;
   //DAVID Find file with filename
   for( KURL::List::ConstIterator find_it = m_list.begin();find_it != m_list.end();find_it++)
   {
      if((*find_it).fileName()==filename)
      {
        //DAVID Find it
	find=true;
	it=m_list.find(*find_it);
      }
   }
   if(find)
   {
       MetaBundle bundle( (*it).url() );        
       EngineController::instance()->play(true,bundle); 
       handleMessage(bundle);
       kdDebug() << "[engine] play: " << endl;            
   }
   else qWarning("File Not Find!!");//this situation should not be happend

}
void Myplayer::stop()
{     
     EngineController::instance()->stop();
     handlePosition(0);
     kdDebug() << "[engine] Stop: " << endl;
}

void Myplayer::pause()
{
     EngineController::instance()->pause();
     kdDebug() << "[engine] Pause: " << endl;
}

void Myplayer::increase_volume()
{
     setVolume(m_Vol+5);        
     kdDebug() << "[Myplayer]increase_Vol ++: " << endl;
}

void Myplayer::decrease_volume()
{
     setVolume(m_Vol-5);
     kdDebug() << "[Myplayer]decrease_Vol --: " << endl;
}

void Myplayer::setVolume(int percent)
{
     if( percent < 0 ) m_Vol = 0;
     else if( percent > 100) m_Vol = 100;
     else m_Vol = percent;
     EngineController::instance()->setVolume(m_Vol);
     emit volumeMessage(m_Vol);
     kdDebug() << "[Myplayer]setVolume: " << m_Vol << endl;
}

void Myplayer::next()
{
     if(!m_list.isEmpty())//DAVID Check list empty
     {
       EngineController::instance()->next();
       kdDebug() << "[engine] Next: " << endl;
     }
     else 
     {
     
       EngineController::instance()->stop();
     }
}

void Myplayer::previous()
{
     if(!m_list.isEmpty())
     {
       EngineController::instance()->previous();
       kdDebug() << "[engine] Previous: "<< endl;
     }
     else EngineController::instance()->stop();
     
}

//=====================Handle=Slot=================================
void Myplayer::handleNext()
{
     kdDebug() << "[engine] hanleNext: " << endl;
     if(m_random)
     {
      qWarning("Myplayer::random play item");
       it = m_list.begin();
       int randomNum = KApplication::random() % m_list.count();
       for(int i = 0;it != m_list.end(); it++)
       {
         if(i == randomNum)break;
	 else i++;
       }
     }
     else ++it;
   
     if(it != m_list.end())
     {
          EngineController::instance()->stop();
          //kdDebug() << "[engine] play: " << (*it).url();
          MetaBundle bundle( (*it).url() );  
	  EngineController::instance()->play(true,bundle);     
	  handleMessage(bundle);
     }
     else
     {
        
        if(m_repeat)
	{
	   it = m_list.begin();
	   qWarning("Myplayer::repeat play item");
	   MetaBundle bundle( (*it).url());
	   EngineController::instance()->play(true,bundle);
	   handleMessage(bundle);
	}
	
	else 
	{      
	     //  qWarning("=======================");
	     //  EngineController::instance()->stop();  
	   
	}
     }
}

void Myplayer::handlePrevious()
{
//     EngineBase *engine = EngineController::engine();
     kdDebug() << "[engine] hanlePrevious: " << endl;
     if(it != m_list.begin())
     {
        --it;
        MetaBundle bundle( (*it).url() );  
//	if(engine->state() == EngineBase::Playing)
          EngineController::instance()->play(true,bundle); 
	handleMessage(bundle);    
     }
     else
     {
        it = m_list.end();
	--it;
	MetaBundle bundle( (*it).url());
//	if(engine->state() == EngineBase::Playing)
	  EngineController::instance()->play(true,bundle);
	handleMessage(bundle);
     }
}

void Myplayer::handleRepeat(bool repeat)
{
     m_repeat = repeat;      
}

void Myplayer::handleRandom(bool random)
{
     m_random = random;
}

void Myplayer::handlePosition(int position)
{    
     emit positionMessage(position);     
}

void Myplayer::handleSlider(int sliderValue)
{
     kdDebug() << "[Myplayer]sliderValue: "<< sliderValue << endl;
     EngineBase *engine = EngineController::engine();
     //if ( engine->state() == EngineBase::Playing )
    // {
        engine->seek( sliderValue*1000 );
//     }
}

void Myplayer::handlePlayItem(KURL &url)
{
     KURL::List::Iterator check_it = m_list.find(url);      
     if(check_it != m_list.end())
       {
       	  it = check_it;
	  play();
	  kdDebug() << "Find Item "<< endl;
       }
     else kdDebug() << "NO this item!! " << endl;
}

//===========================================

void Myplayer::add(KURL::List &list)
{     
     if(!m_list.isEmpty())//Not Empty
     {
        kdDebug() << "PlayList is not empty !!" << endl;
	KURL::List add_list = list;
	for( KURL::List::ConstIterator add_it = add_list.begin();add_it != add_list.end();add_it++)
    	{
              m_list.append( (*add_it).url() );
    	}	
     }
     else
     {
        m_list = list;
        it = m_list.begin();
        kdDebug() << "[Myplayer::add]: " << (*it).url() << endl;
     }
}

void Myplayer::clearMedia()
{    
    if(m_list.isEmpty())kdDebug() << "[Myplayer::clearMedia]: it's empty"<< endl;
    else{
       m_list.clear();     
       kdDebug() << "[Myplayer::clearMedia]: it's clear " << endl;	
    }
}

void Myplayer::removeMedia(KURL::List &remove_list)
{       
    KURL::List::ConstIterator check_it;
        
    if(m_list.isEmpty())kdDebug() << "[Myplayer::removeMedia]: it's empty"<< endl;
    else{
    		for( KURL::List::ConstIterator remove_it = remove_list.begin();remove_it != remove_list.end();remove_it++)
        	{
     	  		check_it = m_list.find((*remove_it).url());      
	  		if(check_it != m_list.end())
	  		{
	    			m_list.remove((*check_it).url());
	    			kdDebug() << "Remove Item "<< endl;
	  		}
	  		else kdDebug() << "NO this item!! " << endl;
        	}
	
		for( KURL::List::ConstIterator refresh_it = m_list.begin();refresh_it != m_list.end();refresh_it++)  
		{
	  		if((*refresh_it).isEmpty())
	  		{
	    			for(check_it = refresh_it; check_it != m_list.end();)
	      			(*check_it).url() = (*(check_it++)).url();	      	    
	  		}	  
		}
		it = m_list.begin();   
    } 
}

//=================Signal======================

void Myplayer::handleMessage(const MetaBundle &bundle)
{
    int m_length = bundle.length();
    int m_bitrate = bundle.bitrate();
    QString m_title = bundle.title();
    QString m_artist = bundle.artist();
    QString m_album = bundle.album();

    emit trackMessage(m_length,m_bitrate,m_title,m_artist,m_album);
}

//==============Private=Function==============

void Myplayer::savePlaylist()
{
    QFile file( "file.txt" );
    if ( file.open( IO_WriteOnly ) ) {
        QTextStream stream( &file );
          for(KURL::List::Iterator save_it = m_list.begin(); save_it != m_list.end(); ++save_it)
            stream << (*save_it).url() << "\n";
        file.close();
kdDebug() << "save file finished!!"<< endl;	
    }    
}

void Myplayer::restorePlaylist()
{
    QFile file( "file.txt" );
    if ( file.open( IO_ReadOnly ) ) {
        QTextStream stream( &file );            
        while ( !stream.atEnd() ) {
             KURL url(stream.readLine()); // line of text excluding '\n'         
             m_list << url;
        }
	kdDebug() << "Load Playlist "<< endl;
        file.close();
    }
}
void Myplayer::initlist(KURL::List & list)
{
  m_list=list;
  it = m_list.begin();
  kdDebug() << "[Myplayer::add]: " << (*it).url() << endl;
}
#include "Myplayer.moc" 
