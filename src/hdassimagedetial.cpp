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
#include "hdassimagedetial.h"
#include <kdebug.h>
#include <qpainter.h>
#include <qimage.h>
//****************************************************
//This QWidget provides the function of Image showing and provide the function of album
//
//****************************************************
hdassImageDetial::hdassImageDetial(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
	xSetup();
}


hdassImageDetial::~hdassImageDetial()
{

}
//****************************************************
//This function initialize all necessary item
//
//****************************************************
void hdassImageDetial::xSetup()
{
   //DAVID Initialize here
   //DAVID Initial the currentImage with white null pix
   currentImage=QPixmap(750,330);
   //set the background image
   //setBackgroundPixmap(currentImage);
}
//****************************************************
//This function resize the hdassImageDetial instance actual size in apperence.
//
//****************************************************
void hdassImageDetial::slotResize(int width,int height)
{
	//resize(width,height);
}
//****************************************************
//This Set the Image ,and show it
//
//****************************************************
void hdassImageDetial::slotSetImage(KURL url)
{

   currentImage=QPixmap(url.path());
   int width ,height;
   width=currentImage.width();
   height=currentImage.height();
   QPixmap draw(QSize(750,330));
   QPainter p(&draw);

   p.fillRect(0,0,750,330,Qt::black);
   if(width<600&&height<330)
   {
       //DAVID draw image at center
       p.drawPixmap((375-width/2),(165-height/2),currentImage);
   }

   else
   {
   	if(11*width>20*height)
	{
		int newheight=(600*height/width);
		QImage rescale=currentImage.convertToImage().scale(600,newheight);
		p.drawImage(75,165-newheight/2,rescale);
		
	}
	else
	{
		int newwidth=(330*width/height);
		QImage rescale=currentImage.convertToImage().scale(newwidth,330);
		p.drawImage((375-newwidth/2),0,rescale);
	}
   }	
   p.end();
   setBackgroundPixmap(draw);
}

#include "hdassimagedetial.moc"
