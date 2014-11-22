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
 #include "hdassalbum.h"
#include <kdebug.h>
#include <qpainter.h>
#include <qimage.h>
#include <qdir.h>
#include <qstringlist.h>
hdassAlbum::hdassAlbum(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
   xSetup();
}


hdassAlbum::~hdassAlbum()
{

}

void hdassAlbum::xSetup()
{
  //DAVID Read album file list 
  AlbumListFileName="AlbumList.txt";
  ReadAlbumList(AlbumListFileName);
  
 

  //DAVID Set the switching time
  switchtime=3;
  //DAVID Set the timer
  timer =new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(slotNextImage()));
  
  //DAVID Draw a pix first
  KURL url((*it).url());
  QPixmap pix;
  pix.load(url.path());
  DrawImage(pix);
  timer->stop();
  
}
void hdassAlbum::AddImageToAlbum(KURL addimage)
{
   AlbumList<<addimage;
}

void hdassAlbum::RemoveImageFromAlbum(KURL removeimage)
{
  AlbumList.remove(removeimage);
}
void hdassAlbum::ChangeMode(AlbumMode mode)
{

}
void hdassAlbum::slotModeChange(int mode)
{

}
void hdassAlbum::ReadAlbumList(QString filepath)
{
	//DAVID open the file
	AlbumFile=new QFile(filepath);
	if(AlbumFile->open(IO_ReadOnly))
	{
		//Read KURL from file to KURLList
		QTextStream stream( AlbumFile );
		while(!stream.atEnd())
		{
			KURL url(stream.readLine());
			//kdDebug()<<url.path();
			AlbumList<<url;
		}
	}
	else
	{
		kdDebug()<<"hdassAlbum::ReadAlbumList ::: file not opened!!";
	}
	it=AlbumList.begin();
}

void hdassAlbum::SaveAlbumList()
{

}

void hdassAlbum::slotPreviousImage()
{
	//DAVID Read Image
	it--;
	if(it!=AlbumList.end())
	{
		KURL url((*it).url());
		QPixmap pix;
		pix.load(url.path());
		DrawImage(pix);
	}
}

void hdassAlbum::slotNextImage()
{
	//DAVID Read Image
	it++;
	if(it!=AlbumList.end())
	{
		KURL url((*it).url());
		QPixmap pix;
		pix.load(url.path());
		DrawImage(pix);
	}
}

void hdassAlbum::slotPlayNStop()
{
	if(timer->isActive ())
	{
		timer->stop();
	}
	else
	{
		timer->start(switchtime*1000,FALSE);
	}
}


void hdassAlbum::slotSetSwitchingTime(int time)
{
  switchtime=time;
}

void hdassAlbum::SlideShow()
{
     qWarning("hdassAlbum::SlideShow()!!");
     timer->start(switchtime*1000,FALSE);
}

void hdassAlbum::DrawImage(QPixmap pix)
{
   
   
   int width ,height;
   width=pix.width();
   height=pix.height();
   
   QPixmap draw(QSize(800,540));
   QPainter p(&draw);

   p.fillRect(0,0,800,540,Qt::black);
   if(width<800&&height<540)
   {
       //DAVID draw image at center
       p.drawPixmap((400-width/2),(270-height/2),pix);
   }

   else
   {
   	if(11*width>20*height)
	{
		int newheight=(800*height/width);
		QImage rescale=pix.convertToImage().scale(800,newheight);
		p.drawImage(0,270-newheight/2,rescale);
		
	} 
	else
	{
		int newwidth=(540*width/height);
		QImage rescale=pix.convertToImage().scale(newwidth,540);
		p.drawImage((400-newwidth/2),0,rescale);
	}
   }	
   p.end();
   setBackgroundPixmap(draw);
}


#include "hdassalbum.moc"
