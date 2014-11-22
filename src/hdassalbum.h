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
#ifndef HDASSALBUM_H
#define HDASSALBUM_H

#include <qwidget.h>
#include <kurl.h>
#include <qptrlist.h>
#include <qpixmap.h>
#include <qfile.h>
#include <qstring.h>
#include <qtimer.h>

/**
@author root
*/
class hdassAlbum : public QWidget
{
Q_OBJECT
enum AlbumMode
{
  Album=0,
  Clock     
};
public:
    hdassAlbum(QWidget *parent = 0, const char *name = 0);

    ~hdassAlbum();
    void xSetup();
    void SlideShow();
    void DrawImage(QPixmap pix);
    KURL::List::ConstIterator it;
    KURL::List AlbumList,FloderList;
    QPtrList <QPixmap> PixList;

public slots:
    void AddImageToAlbum(KURL addimage);
    void RemoveImageFromAlbum(KURL removeimage);
    void ChangeMode(AlbumMode mode);
    void slotNextImage();
    void slotPreviousImage();
    void slotPlayNStop();
    void slotModeChange(int);
    void slotSetSwitchingTime(int time);
private :
    int switchtime;
    QString AlbumListFileName;
    QFile *AlbumFile;
    QTimer *timer;
    void ReadAlbumList(QString filename);
    void SaveAlbumList();
};

#endif
