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
#ifndef SUBBARALBUMCLOCK_H
#define SUBBARALBUMCLOCK_H

#include <qwidget.h>
#include <qpixmap.h>
#include "skinbutton.h"
#include "global_define.h"
/**
@author sonicat
*/
class SubBarAlbumClock : public QWidget
{
enum SLIDESHOWSTATE
{
 	GO=0,
 	STOP
};
Q_OBJECT
public:
    SubBarAlbumClock(QWidget *parent = 0, const char *name = 0);

    ~SubBarAlbumClock();
    void xSetup();
    SkinButton *SubBarBtnAlbumClock,*SubBarBtnPrevious,*SubBarBtnPlayNPause,*SubBarBtnNext;
public slots:
   
   void slotChangeMode();
   void slotChangePlayNPauseBtnGraphic();
signals:
  void signalAlbumClockModeChangeToDispalyArea(int);
     
private:
   QPixmap *btnGraphic[12];
   QPixmap pixBackground;
   void ChangeButtonGraphic(int);
   SLIDESHOWSTATE slideshowstate;
};

#endif
