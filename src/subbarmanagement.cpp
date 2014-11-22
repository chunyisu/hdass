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
#include "subbarmanagement.h"

SubBarManagement::SubBarManagement(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
  xSetup();
}


SubBarManagement::~SubBarManagement()
{
}

void SubBarManagement::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/SubBarBackground.png");
   setBackgroundPixmap(pixBackground);
   
   //DAVID init state
   MMtype=em_mmmusic;
   
   //Btn Graphic
   BtnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Floder.png");
   BtnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Floder-Active.png");
   BtnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Paste.png");
   BtnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Paste-Active.png");
   BtnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Cut.png");
   BtnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Cut-Active.png");
   BtnGraphic[6]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Delete.png");
   BtnGraphic[7]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Delete-Active.png");
   BtnGraphic[8]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Music.png");
   BtnGraphic[9]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Music-Active.png");
   BtnGraphic[10]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Image.png");
   BtnGraphic[11]=new QPixmap("/root/kde_application/hdass08/skin/Bar-MM-Btn-Image-Active.png");
   
   SubBtnMM_Floder=new SkinButton(this);
   SubBtnMM_Paste=new SkinButton(this);
   SubBtnMM_Cut=new SkinButton(this);
   SubBtnMM_Delete=new SkinButton(this);
   SubBtnMM_MusicNImage=new SkinButton(this);
   
   SubBtnMM_Floder->setPixmaps(BtnGraphic[0],BtnGraphic[1]);
   SubBtnMM_Floder->setGeometry(197,0,60,80);
   SubBtnMM_Floder->show();
   
   SubBtnMM_Paste->setPixmaps(BtnGraphic[2],BtnGraphic[3]);
   SubBtnMM_Paste->setGeometry(263,0,60,80);
   SubBtnMM_Paste->show();
   
   SubBtnMM_Cut->setPixmaps(BtnGraphic[4],BtnGraphic[5]);
   SubBtnMM_Cut->setGeometry(329,0,60,80);
   SubBtnMM_Cut->show();
   
   SubBtnMM_Delete->setPixmaps(BtnGraphic[6],BtnGraphic[7]);
   SubBtnMM_Delete->setGeometry(391,0,60,80);
   SubBtnMM_Delete->show();
   
   SubBtnMM_MusicNImage->setPixmaps(BtnGraphic[8],BtnGraphic[9]);
   SubBtnMM_MusicNImage->setGeometry(457,0,80,80);
   SubBtnMM_MusicNImage->show();
   
   //DAVID Connect buttons
   QObject::connect(SubBtnMM_MusicNImage,SIGNAL(pressed()),this,SLOT(slotChangeBtnImage()));
   QObject::connect(SubBtnMM_Floder,SIGNAL(pressed()),this,SLOT(slotBtnMkFloder()));
   QObject::connect(SubBtnMM_Paste,SIGNAL(pressed()),this,SLOT(slotBtnPaste()));
   QObject::connect(SubBtnMM_Cut,SIGNAL(pressed()),this,SLOT(slotBtnCut()));
   QObject::connect(SubBtnMM_Delete ,SIGNAL(pressed()),this,SLOT(slotBtnDelete()));
}
void  SubBarManagement::slotChangeBtnImage()
{
   if(MMtype==em_mmmusic)
   {
      MMtype=em_mmimage;
      SubBtnMM_MusicNImage->setPixmaps(BtnGraphic[10],BtnGraphic[11]);
      emit signalManagementModeChange(0);
   }
   else
   {
     MMtype=em_mmmusic;
     SubBtnMM_MusicNImage->setPixmaps(BtnGraphic[8],BtnGraphic[9]);
     emit signalManagementModeChange(1);
   }
}

void SubBarManagement::slotBtnMkFloder()
{
  emit signalMkdir();
}

void SubBarManagement::slotBtnPaste()
{
  emit singalPasteFUNC_MEDIAM();
}

void SubBarManagement::slotBtnCut()
{
  emit signalCutFUNC_MEDIAM();
}

void SubBarManagement::slotBtnDelete()
{
  emit signalDeleteItem();
}
#include "subbarmanagement.moc"
