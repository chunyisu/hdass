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
#include "DownFile.h"

#include <kdebug.h>


DownFile::DownFile(const KURL &url)   
{  
kdDebug() << "DownFile -> url -> " << url << endl;
kdDebug() << "DownFile -> host -> " << url.host() << endl;      
kdDebug() << "DownFile -> FileName -> " << url.fileName() << endl;    
    downloadfile = new QFile( url.fileName() );
    downloadfile->open( IO_WriteOnly );
    
    http = new QHttp(this);
    http->setHost(url.host());
    http->get( url.path(),downloadfile); 
    connect(http, SIGNAL(done(bool)), this, SLOT(handleDone(bool)));  
    
//    KURL src("http://140.116.5.200/~f7490124/Browser/Macgyver.mp3");
//    KURL des("file:/home/karban/Macgyver.mp3");
//    KIO::FileCopyJob testfile(src,des,777,false,true,true,true);
//    testfile.slotStart();
//    KIO::TransferJob *job = KIO::get( src, false, true );
//    connect(job,SIGNAL(data(KIO::Job *,const QByteArray &)),this,SLOT(handleData(KIO::Job *, const QByteArray &)));
}

DownFile::~DownFile()
{

}

void DownFile::handleDone(bool error)
{
     downloadfile->close();
kdDebug() << "Download Finish !!!!!!!!!! "<< endl; 
     emit Finished(error);        
}

/*
void DownFile::handleData(KIO::Job *job, const QByteArray &data)
{
kdDebug()<< "Data from the slave has arrived. " << endl;
}
*/
#include "DownFile.moc"