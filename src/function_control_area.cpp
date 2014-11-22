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
#include "function_control_area.h"
#include <qbitmap.h>
Function_Control_Area::Function_Control_Area(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
        xSetup();
}


Function_Control_Area::~Function_Control_Area()
{
}

void Function_Control_Area::xSetup()
{
   QBitmap mask=QBitmap("/root/kde_application/hdass08/skin/function_control_masking.png");
   setMask(mask);
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/FunctionAreaBackground.png");
   setBackgroundPixmap(pixBackground);
   //InitButton Graphic
   btnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-internet.png");
   btnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-internet-active.png");
   btnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-player.png");
   btnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-player-active.png");
   btnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-management.png");
   btnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-management-active.png");
   btnGraphic[6]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-albumclock.png");
   btnGraphic[7]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-albumclock-active.png");
   btnGraphic[8]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-setting.png");
   btnGraphic[9]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-setting-active.png");
   btnGraphic[10]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-close.png");
   btnGraphic[11]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-close-active.png");
   btnGraphic[12]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-imagedetial.png");
   btnGraphic[13]=new QPixmap("/root/kde_application/hdass08/skin/skin-function-button-imagedetial-active.png");
   
   //Init Skinbutton
   fun_btn_internet             =new SkinButton(this);
   fun_btn_player              =new SkinButton(this);
   fun_btn_management     =new SkinButton(this);
   fun_btn_albumclock       =new SkinButton(this);
   fun_btn_setting             =new SkinButton(this);
   fun_btn_close               =new SkinButton(this);
   fun_btn_imagedetial      =new SkinButton(this);
   
   fun_btn_internet->setPixmaps(btnGraphic[0],btnGraphic[1]);
   fun_btn_internet->setGeometry(0,0,135,135);
   fun_btn_internet->show();
   
   fun_btn_player->setPixmaps(btnGraphic[2],btnGraphic[3]);
   fun_btn_player->setGeometry(0,0,135,135);
   fun_btn_player->hide();
   
   fun_btn_management->setPixmaps(btnGraphic[4],btnGraphic[5]);
   fun_btn_management->setGeometry(0,0,135,135);
   fun_btn_management->hide();
   
   fun_btn_albumclock->setPixmaps(btnGraphic[6],btnGraphic[7]);
   fun_btn_albumclock->setGeometry(0,0,135,135);
   fun_btn_albumclock->hide();
   
   fun_btn_setting->setPixmaps(btnGraphic[8],btnGraphic[9]);
   fun_btn_setting->setGeometry(0,0,135,135);
   fun_btn_setting->hide();
   
   fun_btn_close->setPixmaps(btnGraphic[10],btnGraphic[11]);
   fun_btn_close->setGeometry(0,0,135,135);
   fun_btn_close->hide();
   
   fun_btn_imagedetial->setPixmaps(btnGraphic[12],btnGraphic[13]);
   fun_btn_imagedetial->setGeometry(0,0,135,135);
   fun_btn_imagedetial->hide();
   
   
   
   connect(fun_btn_internet,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
    connect(fun_btn_player,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
     connect(fun_btn_management,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
      connect(fun_btn_albumclock,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
       connect(fun_btn_setting,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
        connect(fun_btn_close,SIGNAL(released()),this,SLOT(slotProcessChangeFunc()));
	connect(fun_btn_imagedetial,SIGNAL(released()),this,SLOT(slotImageDetial()));
      //DAVID Set the Function Control Area State
      
      slotChangeButton(GlobalSetting.intHDASS_FUNCTION_STATE);
      emit signalChangeFunc(GlobalSetting.intHDASS_FUNCTION_STATE);
}

void Function_Control_Area::slotProcessChangeFunc()
{
  //DAVID Process To Next Function
  GlobalSetting.intHDASS_FUNCTION_STATE++;
  GlobalSetting.intHDASS_FUNCTION_STATE%=6;
  //qWarning("FunctionState::%d\n",GlobalSetting.intHDASS_FUNCTION_STATE);
  slotChangeButton(GlobalSetting.intHDASS_FUNCTION_STATE);
  emit signalChangeFunc(GlobalSetting.intHDASS_FUNCTION_STATE);
}

void Function_Control_Area::slotChangeButton(int v)
{
   if(v==em_internet)
   {
     fun_btn_internet->show();
     fun_btn_player->hide();
     fun_btn_management->hide();
     fun_btn_albumclock->hide();
     fun_btn_setting->hide();
     fun_btn_close->hide();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_player)
   {
     fun_btn_internet->hide();
     fun_btn_player->show();
     fun_btn_management->hide();
     fun_btn_albumclock->hide();
     fun_btn_setting->hide();
     fun_btn_close->hide();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_management)
   {
     fun_btn_internet->hide();
     fun_btn_player->hide();
     fun_btn_management->show();
     fun_btn_albumclock->hide();
     fun_btn_setting->hide();
     fun_btn_close->hide();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_albumclock)
   {
     fun_btn_internet->hide();
     fun_btn_player->hide();
     fun_btn_management->hide();
     fun_btn_albumclock->show();
     fun_btn_setting->hide();
     fun_btn_close->hide();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_setting)
   {
     fun_btn_internet->hide();
     fun_btn_player->hide();
     fun_btn_management->hide();
     fun_btn_albumclock->hide();
     fun_btn_setting->show();
     fun_btn_close->hide();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_close)
   {
     fun_btn_internet->hide();
     fun_btn_player->hide();
     fun_btn_management->hide();
     fun_btn_albumclock->hide();
     fun_btn_setting->hide();
     fun_btn_close->show();
     fun_btn_imagedetial->hide();
   }
   else if(v==em_imagedetial)
   {
    fun_btn_internet->hide();
     fun_btn_player->hide();
     fun_btn_management->hide();
     fun_btn_albumclock->hide();
     fun_btn_setting->hide();
     fun_btn_close->hide();
     fun_btn_imagedetial->show();
   }
}

void Function_Control_Area::slotImageDetial()
{
      //Back to em_management state
      GlobalSetting.intHDASS_FUNCTION_STATE=em_management;
      slotChangeButton(GlobalSetting.intHDASS_FUNCTION_STATE);
      emit signalChangeFunc(GlobalSetting.intHDASS_FUNCTION_STATE);
      emit signalBackToManagement();
}

void Function_Control_Area::slotShowImageDetial()
{
      GlobalSetting.intHDASS_FUNCTION_STATE=em_imagedetial;
      slotChangeButton(GlobalSetting.intHDASS_FUNCTION_STATE);
      emit signalChangeFunc(GlobalSetting.intHDASS_FUNCTION_STATE);
}

#include "function_control_area.moc"
