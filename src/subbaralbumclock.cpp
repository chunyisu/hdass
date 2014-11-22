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
#include "subbaralbumclock.h"

SubBarAlbumClock::SubBarAlbumClock(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
 xSetup();
}


SubBarAlbumClock::~SubBarAlbumClock()
{
}
void SubBarAlbumClock::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/SubBarBackground.png");
   setBackgroundPixmap(pixBackground);
   
   //InitBtn Graphic
   btnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Album.png");
   btnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Album-Active.png");
   btnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Clock.png");
   btnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Clock-Active.png");
   btnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Previous.png");
   btnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Previous-Active.png");
   btnGraphic[6]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Play.png");
   btnGraphic[7]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Play-Active.png");
   btnGraphic[8]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Pause.png");
   btnGraphic[9]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Pause-Active.png");
   btnGraphic[10]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Next.png");
   btnGraphic[11]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Album-Btn-Next-Active.png");
   //Init Btn
   SubBarBtnAlbumClock=new SkinButton(this);
   SubBarBtnAlbumClock->setPixmaps(btnGraphic[0],btnGraphic[1]);
   SubBarBtnAlbumClock->setGeometry(457,0,80,80);
   SubBarBtnAlbumClock->show();
   
   SubBarBtnPrevious=new SkinButton(this);
   SubBarBtnPrevious->setPixmaps(btnGraphic[4],btnGraphic[5]);
   SubBarBtnPrevious->setGeometry(175,0,60,80);
   SubBarBtnPrevious->show();
   
   SubBarBtnPlayNPause=new SkinButton(this);
   SubBarBtnPlayNPause->setPixmaps(btnGraphic[6],btnGraphic[7]);
   SubBarBtnPlayNPause->setGeometry(240,0,80,80);
   SubBarBtnPlayNPause->show();
   
   SubBarBtnNext=new SkinButton(this);
   SubBarBtnNext->setPixmaps(btnGraphic[10],btnGraphic[11]);
   SubBarBtnNext->setGeometry(323,0,60,80);
   SubBarBtnNext->show();
   
   QObject::connect(SubBarBtnAlbumClock,SIGNAL(pressed()),this,SLOT(slotChangeMode()));
   QObject::connect(SubBarBtnPlayNPause,SIGNAL(pressed()),this,SLOT(slotChangePlayNPauseBtnGraphic()));
  // slideshowstate=AlbumControl::GO;

}

void SubBarAlbumClock::slotChangeMode()
{
  
  // +3 make the value init form em_dispaly_album (3)
  //qWarning("~~~~~~~~%d",GlobalSetting.intHDASS_ALBUMCLOCK_STATE);
  GlobalSetting.intHDASS_ALBUMCLOCK_STATE++;
  GlobalSetting.intHDASS_ALBUMCLOCK_STATE%=2;
  GlobalSetting.intHDSS_DISPLAY_STATE=GlobalSetting.intHDASS_ALBUMCLOCK_STATE+3;
  ChangeButtonGraphic(GlobalSetting.intHDASS_ALBUMCLOCK_STATE);
}

void SubBarAlbumClock::ChangeButtonGraphic(int Mode)
{
    qWarning("~~~~~~~~%d",GlobalSetting.intHDSS_DISPLAY_STATE);
    emit signalAlbumClockModeChangeToDispalyArea(GlobalSetting.intHDSS_DISPLAY_STATE);
   if(!Mode)//Album
   SubBarBtnAlbumClock->setPixmaps(btnGraphic[0],btnGraphic[1]);
   else//Clock
   SubBarBtnAlbumClock->setPixmaps(btnGraphic[2],btnGraphic[3]);
 
}

void SubBarAlbumClock::slotChangePlayNPauseBtnGraphic()
{
  if(slideshowstate==SubBarAlbumClock::STOP)
 {
  slideshowstate=SubBarAlbumClock::GO;
  SubBarBtnPlayNPause->setPixmaps(btnGraphic[6],btnGraphic[7]);
 }
 else
 {
  slideshowstate=SubBarAlbumClock::STOP;
  SubBarBtnPlayNPause->setPixmaps(btnGraphic[8],btnGraphic[9]);
 }
}

#include "subbaralbumclock.moc"
