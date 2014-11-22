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
#include "imagedetial.h"
#include <qdir.h>
ImageDetial::ImageDetial(QWidget *parent, const char *name)
 : hdassAlbum(parent, name)
{
}


ImageDetial::~ImageDetial()
{
}
void ImageDetial::slotShowFloder(KURL floder_file)
{
   //DAVID Read All Files in the floder of  floder_file
   
   //DAVID Get the Floder path
   qWarning(floder_file.directory());
   QDir dir;
   dir.setPath(floder_file.directory());
   const QFileInfoList * files=dir.entryInfoList();
   QFileInfoListIterator its( *files );
   QFileInfo * fi;
   //DAVID Add all file to FloderList
   while( (fi=its.current())!=0 )
   {
     if(fi->extension()=="jpg")
     {
       qWarning(fi->filePath());
       FloderList<<KURL(fi->filePath());
     }
     ++its;
   }
   it=FloderList.find(floder_file);
   
   KURL url((*it).url());
		QPixmap pix;
		pix.load(url.path());
		DrawImage(pix);
}

#include "imagedetial.moc"
