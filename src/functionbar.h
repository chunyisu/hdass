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
#ifndef FUNCTIONBAR_H
#define FUNCTIONBAR_H

#include <qwidget.h>
#include <qpixmap.h>
#include "global_define.h"
#include "enum.h"
#include "subbaralbumclock.h"
#include "subbarinternet.h"
#include "subbarplayer.h"
#include "subbarmanagement.h"
#include "subbarsetting.h"
#include "subbarclose.h"

/**
@author sonicat
*/
class FunctionBar : public QWidget
{
Q_OBJECT
public:
    FunctionBar(QWidget *parent = 0, const char *name = 0);

    ~FunctionBar();
    void xSetup();
    SubBarAlbumClock *BarAC,*BarID;
    SubBarInternet *BarInternet;
    SubBarPlayer *BarPlayer;
    SubBarManagement *BarManagement;
    SubBarSetting *BarSetting;
    SubBarClose *BarClose;
public slots:
    void slotChangeFunctionSubBar(int);
signals:
    void siganlChangeDisplayAreaMode(int);    
private:
   QPixmap pixBackground;
};

#endif
