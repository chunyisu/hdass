/***************************************************************************
 *   Copyright (C) 2004 by root                                            *
 *   root@colicoli                                                         *
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
#include "mediamanagement.h"
#include <kdebug.h>
mediamanagement::mediamanagement(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
    xSetup();
}


mediamanagement::~mediamanagement()
{
}

void mediamanagement::xSetup()
{
  //Initial here
  //DAVID set backgorund color.
  setPaletteBackgroundColor(QColor(0,0,0));
  resize(750,500);
  musicsplitter = new QSplitter( this );
  
  musicDir=new DirectoryView(musicsplitter,"MusicDir",true);
  musicDir->addColumn( "Name" );
  musicDir->setTreeStepSize( 40 );
  musicroot = new Directory( musicDir, "/data/Media/MP3/" );
  
  musicroot->setOpen( TRUE );
  musicsplitter->setResizeMode( musicDir, QSplitter::KeepSize );
  musicFIV = new QtFileIconView( "/", musicsplitter );
  musicFIV->setSelectionMode( QIconView::Extended );
  musicsplitter->setGeometry(0,0,width(),height());
  
  
   connect( musicDir, SIGNAL( folderSelected( const QString & ) ),
   	     musicFIV, SLOT ( setDirectory( const QString & ) ) );

  ///////////////////////////////////////////////////////////////////	     
  imagesplitter = new QSplitter( this );
  
  imgDir=new DirectoryView(imagesplitter,"MusicDir",true);
  imgDir->addColumn( "Name" );
  imgDir->setTreeStepSize( 40 );
  imgroot = new Directory( imgDir, "/data/Media/IMAGES/" );
  
  imgroot->setOpen( TRUE );
  imagesplitter->setResizeMode( imgDir, QSplitter::KeepSize );
  imgFIV = new QtFileIconView( "/", imagesplitter,"imgFIV",Image );
  imgFIV->setSelectionMode( QIconView::Extended );
  imagesplitter->setGeometry(0,0,width(),height());
  imgdetial =new ImageDetial(this,"ImageDetail");
  imgdetial->setGeometry(0,0,width(),height());
  imgdetial->hide();
  
   connect( imgDir, SIGNAL( folderSelected( const QString & ) ),
   	     imgFIV, SLOT ( setDirectory( const QString & ) ) );
  
  //DAVID Initial Album here	
  //DAVID connect the show image singal to the ImageDetial
  connect(imgFIV,SIGNAL(signalShowTheDetialofImage(KURL )),imgdetial,SLOT(slotShowFloder(KURL )));     
  connect(imgFIV,SIGNAL(signalShowTheDetialofImage(KURL )),this,SLOT(slotShowImage(KURL )));
  
  imagesplitter->hide();

  Mode=1;	     
}
void mediamanagement::slotChangeMode(int mode)
{
  //DAVID Set Mode
  Mode=mode;
  if (mode==0)//Image
  {
      imagesplitter->show();
      musicsplitter->hide();
      imgdetial->hide();
  }
  if(mode==1)
  {
      imagesplitter->hide();
      musicsplitter->show();
      imgdetial->hide();
  }
  if(mode==2)
  {
     imagesplitter->hide();
     musicsplitter->hide();
     imgdetial->show();
  }
}
void mediamanagement::slotDeleteItem()
{
	//qWarning("MediaManagement::slotDeleteItem()");
	//DAVID Check Mode
	kdDebug()<<"Mode:"<<Mode;
	if(Mode==0)//Image
	{
	         //check active area  musicDir or musicFIV
		//Delete Image Current QFileIconViewItem
		if(imgFIV->hasFocus())
		{
			qWarning("---------------1");
			imgFIV->slotDeletCurrItem();
			imgFIV->repaint();
		}
		else if(imgDir->hasFocus())
		{
			qWarning("----------------2");
			Directory *dir;
			for(dir=(Directory *)imgroot->firstChild();dir;dir=(Directory *)dir->nextSibling())
			{
			  if(dir->isSelected())
			  {
			  	qWarning(dir->fullName());
				QDir temp(dir->fullName());
				const QFileInfoList* fileinfolist = temp.entryInfoList();
				if(fileinfolist) 
				{
					QFileInfoListIterator it(*fileinfolist);
					QFileInfo* fi;
					while((fi = it.current()) != 0)
					{
						if(fi->fileName() != "." && fi->fileName() != "..") 
						temp.remove(fi->absFilePath(),true);
						++it;
					}
				}	
				temp.cdUp();
				temp.rmdir(dir->fullName());
				//f.remove();
				delete dir;
			  }
			}
		}
	}
	else if(Mode==1)//music
	{
		//Delete music Current QFileIconViewItem
		qWarning("Mode 1");
		if(musicFIV->hasFocus())
		{
			qWarning("----------------3");
			musicFIV->slotDeletCurrItem();
			musicFIV->repaint();
		}
		else if(musicDir->hasFocus())
		{
		        qWarning("----------------4");
			Directory *dir;
			for(dir=(Directory *)musicroot->firstChild();dir;dir=(Directory *)dir->nextSibling())
			{
			  if(dir->isSelected())
			  {
			  	qWarning(dir->fullName());
				QDir temp(dir->fullName());
				const QFileInfoList* fileinfolist = temp.entryInfoList();
				if(fileinfolist) 
				{
					QFileInfoListIterator it(*fileinfolist);
					QFileInfo* fi;
					while((fi = it.current()) != 0)
					{
						if(fi->fileName() != "." && fi->fileName() != "..") 
						temp.remove(fi->absFilePath(),true);
						++it;
					}
				}	
				temp.cdUp();
				temp.rmdir(dir->fullName());
				//f.remove();
				delete dir;
			  }
			}
			
		}
	}
}
void mediamanagement::slotMkdir(QString dirname)
{	
	if(Mode==0)//Image
	{
		//DAVID MKdir Current QFileIconViewItem
		qWarning("mediamanagement::slotMkdir()::Image!!!");
		imgroot->Mkdir(dirname);
		imgDir->repaint();
		
	}
	else if(Mode==1)//music
	{
		//Delete music Current QFileIconViewItem
		qWarning("mediamanagement::slotMkdir()::music!!!");
		musicroot->Mkdir(dirname);
		musicDir->repaint();
	}
}

void mediamanagement::slotPaste()
{
	if(Mode==0)// image 
	{
		qWarning("mediamanagement::slotPaste()::image");
	}
	else if(Mode==1)//music
	{
		qWarning("mediamanagement::slotPaste()::music");
	}
}
void mediamanagement::slotCut()
{
	if(Mode==0)//image
	{
		qWarning("mediamanagement::slotCut()::image!!");
	}
	else if (Mode==1)//music
	{
		qWarning("mediamanagement::slotCut()::music!!");
	}
}
//*************************************************************************************
//This function hide the splitter
//
//*************************************************************************************
void mediamanagement::slotShowImage(KURL url)
{
	//Set Image
	//DAVID change the mode to the image mode
	slotChangeMode(2);
	emit signalImageDetial();
	
}
void mediamanagement::slotBackToManagement()
{
        slotChangeMode(0);
}

#include "mediamanagement.moc"
