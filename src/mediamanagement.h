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
#ifndef MEDIAMANAGEMENT_H
#define MEDIAMANAGEMENT_H

#include <qfileinfo.h>
#include <qsplitter.h>
#include <qdir.h>
#include <kurl.h>
#include "dirview.h"
#include "qfileiconview.h"
#include "imagedetial.h"
/**
@author root
*/
class mediamanagement : public QWidget
{
Q_OBJECT
public:
    mediamanagement(QWidget *parent = 0, const char *name = 0);
    ~mediamanagement();
    DirectoryView *imgDir;
    DirectoryView *musicDir;
    QtFileIconView *imgFIV;
    QtFileIconView *musicFIV;
    Directory *musicroot,*imgroot;
    ImageDetial * imgdetial;
 public slots:
 void slotChangeMode(int);
 void slotDeleteItem();
 void slotMkdir(QString dirname);
 void slotCut();
 void slotPaste();
 void slotShowImage(KURL url);
 void slotBackToManagement();
 signals:
 void signalImageDetial();
 void signalShowKeyboard();
private:
   void xSetup();
   QSplitter *imagesplitter,*musicsplitter;
   int Mode;
};

#endif
