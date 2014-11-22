/***************************************************************************
 *   Copyright (C) 2005 by sonicat                                         *
 *   is87098@cis.nctu.edu.tw                                               *
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
#include "hdassplaylist.h"
#include <qtextstream.h>
#include "global_define.h"
#include <kdebug.h>
hdassplaylist::hdassplaylist(QObject *parent, const char *name)
 : QObject(parent, name)
{
    xSetup();
}


hdassplaylist::~hdassplaylist()
{
     SaveList();
}

void hdassplaylist::xSetup()
{
      //DAVID ReadListFile
      ReadListFile(GlobalSetting.ListFileName);
}

void hdassplaylist::ReadListFile(QString FileName)
{
   //Clear List
   url_list.clear();
   //ReadFile
   kdDebug()<<FileName<<endl;
   List =new QFile(FileName);
   if ( List->open( IO_ReadOnly ) ) 
   {
        QTextStream stream( List );            
        while ( !stream.atEnd() ) 
        {
               KURL url(stream.readLine()); // line of text excluding '\n'
	       QFile temp(url.path());
	       //check if the file exists
	       if(temp.exists())
	       {
                       url_list << url;
	       }         
             
        }
	 kdError() << "Load Playlist "<< endl;
        List->close();
    }
    else
    {
         kdError() << "PlayList:: "<<FileName<<"can't open!!"<< endl;
	List->close();
    }
}
void hdassplaylist::slotPLRequest()
{
  //DAVID emit the playlist
 
  qWarning("hdassplaylist::slotPLRequest()");
  emit signalPLSend(url_list);
  
}
void hdassplaylist::slotReciveList(KURL::List list,HDASS_ACTION_TYPE act)
{
  if(act==em_remove)
  {
   RemoveList(list);
   SaveList();
  }
  else if(act==em_paste)
  {
    CutList(list);
    SaveList();
  }
  else if(act==em_cut)
  {
    PasteList();
    SaveList();
  }
  else 
  {
    AppendList(list);
    SaveList();
  }
  
}
void hdassplaylist::RemoveList(KURL::List removelist)
{
   for(KURL::List::ConstIterator remove_it = removelist.begin();remove_it != removelist.end();remove_it++)
   {
      url_list.remove(*remove_it);
   }
   emit signalPLSend(url_list);
}
void hdassplaylist::CutList(KURL::List cutlist)
{  
  url_list_cut_buffer=cutlist;
  RemoveList(cutlist);
}
void hdassplaylist::PasteList()
{
   for(KURL::List::ConstIterator paste_it = url_list_cut_buffer.begin();paste_it != url_list_cut_buffer.end();paste_it++)
   {
      url_list.append(*paste_it);
   }
   emit signalPLSend(url_list);
}
void hdassplaylist::SaveList()
{
  //DAVID New Save List File
  List =new QFile(GlobalSetting.ListFileName);
   if ( List->open( IO_WriteOnly ) ) 
   {
        QTextStream stream( List );
	for( KURL::List::ConstIterator iterator = url_list.begin();iterator != url_list.end();iterator++)
        {	
	    if(!(*iterator). isEmpty())
	    {
	    			//DAVID Write to the file
	        stream<<"file:"<<((*iterator).path())<<endl;
	    }	
        }   
	qWarning("SavePlayLists!!");
        List->close();
    }
    else
    {
        
	qWarning("PlayList can't be opened");
	List->close();
    }
  
}

void hdassplaylist::AppendList(KURL::List list)
{
    for(KURL::List::ConstIterator append_it = list.begin();append_it != list.end();append_it++)
   {
      url_list.append(*append_it);
   }
   emit signalPLSend(url_list);
}
#include "hdassplaylist.moc"
