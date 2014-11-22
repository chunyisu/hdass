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
#include "displayarea.h"
#include "global_define.h"
#include <khtmlview.h>
//#include "keyboaed_key.h"
DisplayArea::DisplayArea(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
   xSetup();
}


DisplayArea::~DisplayArea()
{
}

void DisplayArea::xSetup()
{
  //DAVID Set Background   
  setPaletteBackgroundColor(QColor(0,0,0));
   
  Browser =new MyBrowser(this);
  Browser->view()->setGeometry(0,0,800,600);
  Browser->hide();
  
  //DAVID Clock  
  Clock =new hdassClock(this);
  Clock->setGeometry(0,0,800,520);
  Clock->hide();
  
  
   //Set the Album
  Album=new ImageDetial(this,"Album");
  Album->setGeometry(0,0,800,520);
  Album->hide();
  
  //DAVID InfoArea
  
  IA=new InfoArea(this,"IA");
  IA->setGeometry(0,0,800,520);
  IA->hide();
  
  Media =new mediamanagement(this,"mediamanagement");
  Media->setGeometry(20,20,750,500);
  Media->hide();
    
  slotDisplayModeChange(GlobalSetting.intHDSS_DISPLAY_STATE);
 // KeyBoaed_Key *key=new KeyBoaed_Key(this);
 // key->setGeometry(0,0,54,54);
//  key-show();
}

void DisplayArea::slotDisplayModeChange(int displaymode)
{
   
  if(displaymode==em_display_internet)
  {
    Browser->show();
    Clock->hide();
    Album->hide();
    IA->hide();
    Media->hide();
  }
  if(displaymode==em_display_player)
  {
    Browser->hide();
    Clock->hide();
    Album->hide();
    IA->show();
    Media->hide();
  }
  if(displaymode==em_display_management)
  {
    Browser->hide();
    Clock->hide();
    Album->hide();
    IA->hide();
    Media->show();
  }
  if(displaymode==em_display_album)
  {
    Browser->hide();
    Clock->hide();
    Album->show();
    IA->hide();
    Media->hide();
  }
  if(displaymode==em_display_clock)
  {
    Browser->hide();
    Clock->show();
    Album->hide();
    IA->hide();
    Media->hide();
  }
  if(displaymode==em_display_setting)
  {
    Browser->hide();
    Clock->hide();
    Album->hide();
    IA->hide();
    Media->hide();
  }
  if(displaymode==em_display_close)
  {
    Browser->hide();
    Clock->hide();
    Album->hide();
    IA->hide();
    Media->hide();
  }
  
}
#include "displayarea.moc"
