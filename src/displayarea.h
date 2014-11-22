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
#ifndef DISPLAYAREA_H
#define DISPLAYAREA_H

#include <qwidget.h>
#include "enum.h"
#include "hdassclock.h"
#include "MyBrowser.h"
#include "hdassalbum.h"
#include "infoarea.h"
#include "mediamanagement.h"
/**
@author sonicat
*/
class DisplayArea : public QWidget
{
Q_OBJECT
public:
    DisplayArea(QWidget *parent = 0, const char *name = 0);

    ~DisplayArea();
    void xSetup();
    hdassClock *Clock;
    MyBrowser *Browser;
    ImageDetial *Album;
    InfoArea *IA;
    mediamanagement *Media;
public slots:
   void slotDisplayModeChange(int);   

};

#endif
