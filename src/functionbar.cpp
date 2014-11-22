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
#include "functionbar.h"

FunctionBar::FunctionBar(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
   xSetup();
}


FunctionBar::~FunctionBar()
{
}

void FunctionBar::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/FunctionBarBackground.jpg");
   setBackgroundPixmap(pixBackground);
   
   //DAVID Init BarInternet
   BarInternet=new SubBarInternet(this);
   BarInternet->setGeometry(115,0,550,80);
   BarInternet->hide();
   
   //DAVID Init BarPlayer
   BarPlayer=new SubBarPlayer(this);
   BarPlayer->setGeometry(115,0,550,80);
   BarPlayer->hide();
   
   //DAVID Init BarManagement
   BarManagement=new SubBarManagement(this);
   BarManagement->setGeometry(115,0,550,80);
   BarManagement->hide();
   
   //DAVID Init BarAC
   BarAC=new SubBarAlbumClock(this);
   BarAC->setGeometry(115,0,550,80);
   BarAC->hide();
   
   //DAVID Init SubBarSetting
   BarSetting=new SubBarSetting(this);
   BarSetting->setGeometry(115,0,550,80);
   BarSetting->hide();
   
   //DAVID Init BarClose
   BarClose=new SubBarClose(this);
   BarClose->setGeometry(115,0,550,80);
   BarClose->hide();
   
   //DAVID Init BarID ,ImageDetial
   BarID=new SubBarAlbumClock(this);
   BarID->setGeometry(115,0,550,80);
   BarID->hide();
   
   //DAVID Set the Current Setting to the ba state
   slotChangeFunctionSubBar(GlobalSetting.intHDASS_FUNCTION_STATE);
   
}

void FunctionBar::slotChangeFunctionSubBar(int FuncMode)
{
  #if TRACE
  qWarning("slotChangeFunctionSubBar::%d",FuncMode);
  #endif
  if(FuncMode==em_internet)
  {
    BarInternet->show();
    BarPlayer->hide();
    BarManagement->hide();
    BarAC->hide();
    BarSetting->hide();
    BarClose->hide();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    GlobalSetting.intHDSS_DISPLAY_STATE=em_display_internet;
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDSS_DISPLAY_STATE);    
  }
  else if(FuncMode==em_player)
  {
    BarInternet->hide();
    BarPlayer->show();
    BarManagement->hide();
    BarAC->hide();
    BarSetting->hide();
    BarClose->hide();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    GlobalSetting.intHDSS_DISPLAY_STATE=em_display_player;
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDSS_DISPLAY_STATE);    
  }
  else if(FuncMode==em_management)
  {
    BarInternet->hide();
    BarPlayer->hide();
    BarManagement->show();
    BarAC->hide();
    BarSetting->hide();
    BarClose->hide();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    GlobalSetting.intHDSS_DISPLAY_STATE=em_display_management;
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDSS_DISPLAY_STATE);    
  
  }
  else if(FuncMode==em_albumclock)
  {
    BarInternet->hide();
    BarPlayer->hide();
    BarManagement->hide();
    BarAC->show();
    BarSetting->hide();
    BarClose->hide();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDASS_ALBUMCLOCK_STATE+3);    
  }
  else if(FuncMode==em_setting)
  {
    BarInternet->hide();
    BarPlayer->hide();
    BarManagement->hide();
    BarAC->hide();
    BarSetting->show();
    BarClose->hide();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    GlobalSetting.intHDSS_DISPLAY_STATE=em_display_setting;
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDSS_DISPLAY_STATE);    
  }
  else if(FuncMode==em_close)
  {
    BarInternet->hide();
    BarPlayer->hide();
    BarManagement->hide();
    BarAC->hide();
    BarSetting->hide();
    BarClose->show();
    BarID->hide();
    //DAVID Change  DisplayArea Mode
    GlobalSetting.intHDSS_DISPLAY_STATE=em_display_close;
    emit siganlChangeDisplayAreaMode(GlobalSetting.intHDSS_DISPLAY_STATE);    
  }
   else if(FuncMode==em_imagedetial)
  {
    BarInternet->hide();
    BarPlayer->hide();
    BarManagement->hide();
    BarAC->hide();
    BarSetting->hide();
    BarClose->hide();
    BarID->show();
  }
}
#include "functionbar.moc"
