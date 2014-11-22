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

#include "hdass08.h"

#include <qlabel.h>
#include <kmainwindow.h>
#include <klocale.h>
#include "enum.h"
#include <qstring.h>

HDASS08::HDASS08()
    : KMainWindow( 0, "HDASS08",WStyle_NoBorder | WStyle_Customize  )
{
 //DAVID Setting BackGround pixmap
  pixBackground.load("/home/sonicat/hdass08/skin-background.jpg");
  setBackgroundPixmap(pixBackground);
  xSetup();
}

HDASS08::~HDASS08()
{
}

void HDASS08::xSetup()
{
  //DAVID Init PlayList Here
  HDASS_PLAY_LIST=new hdassplaylist(this,"PlayList");
  
  //DAVID Show the Function Control Widget 
  
  Display =new DisplayArea(this,"DisplayArea");
  Display->setGeometry(0,0,800,600);
  Display->show();
  
  ControlArea=new Function_Control_Area(this,"ControlArea");
  ControlArea->setGeometry(665,465,135,135);
  ControlArea->show();
  
  
  Bar=new FunctionBar(this,"FunctionBar");
  Bar->setGeometry(0,520,665,80);
  Bar->show();
  
  HDASS_KEYBOARD =new keyboard(this,"HDASS_KEYBOARD");
  HDASS_KEYBOARD->move(100,100);
  HDASS_KEYBOARD->hide();
  strKeyboardString=QString();
  /*

  */
  QObject::connect(ControlArea,SIGNAL(signalChangeFunc(int )),Bar,SLOT(slotChangeFunctionSubBar(int )));
  QObject::connect(ControlArea,SIGNAL(signalBackToManagement()),Display->Media,SLOT(slotBackToManagement()));
  QObject::connect(Bar->BarAC,SIGNAL(signalAlbumClockModeChangeToDispalyArea(int )),Display,SLOT(slotDisplayModeChange(int )));
  QObject::connect(Bar,SIGNAL(siganlChangeDisplayAreaMode(int)),Display,SLOT(slotDisplayModeChange(int )));
  
  //DAVID Handle the connection between Bar and Display Buttons
  QObject::connect(Bar->BarInternet->SubBarBtnInternet_Next, SIGNAL(clicked()), Display->Browser, SLOT(handleNext()));
  QObject::connect(Bar->BarInternet->SubBarBtnInternet_Previous, SIGNAL(clicked()), Display->Browser, SLOT(handlePrevious()));
  QObject::connect(Bar->BarInternet->SubBarBtnInternet_Home, SIGNAL(clicked()), Display->Browser, SLOT(handleHome()));
  
  //DAVID Handle the connection betwwen Album Control Buttons and all theirs corresponding function
  QObject::connect(Bar->BarAC->SubBarBtnPrevious,SIGNAL(pressed()),Display->Album,SLOT(slotPreviousImage()));
  QObject::connect(Bar->BarAC->SubBarBtnNext,SIGNAL(pressed()),Display->Album,SLOT(slotNextImage()));
  QObject::connect(Bar->BarAC->SubBarBtnPlayNPause,SIGNAL(pressed()),Display->Album,SLOT(slotPlayNStop()));
  
  //DAVID Handle the connection between  ImageDetail Control Buttons and their  corresopnding functions 
  QObject::connect(Bar->BarID->SubBarBtnPrevious,SIGNAL(pressed()),Display->Media->imgdetial,SLOT(slotPreviousImage()));
  QObject::connect(Bar->BarID->SubBarBtnNext,SIGNAL(pressed()),Display->Media->imgdetial,SLOT(slotNextImage()));
  QObject::connect(Bar->BarID->SubBarBtnPlayNPause,SIGNAL(pressed()),Display->Media->imgdetial,SLOT(slotPlayNStop()));
  
  //DAVID Handle the connection between Volume Buttons and the Myplayer
  QObject::connect(Display->IA->IABtnVolumeUp, SIGNAL(pressed()), Bar->BarPlayer->m_player, SLOT(increase_volume()));
  QObject::connect(Display->IA->IABtnVolumeDown, SIGNAL(pressed()), Bar->BarPlayer->m_player, SLOT(decrease_volume()));
  
  QObject::connect(Display->IA,SIGNAL(signalReadList()),HDASS_PLAY_LIST,SLOT(slotPLRequest()));
  QObject::connect(HDASS_PLAY_LIST,SIGNAL(signalPLSend(KURL::List )),Display->IA,SLOT(slotReadListFromPlayList(KURL::List )));
  QObject::connect(Bar->BarPlayer,SIGNAL(signalRequestPL()),HDASS_PLAY_LIST,SLOT(slotPLRequest()));
  QObject::connect(HDASS_PLAY_LIST,SIGNAL(signalPLSend(KURL::List )),Bar->BarPlayer,SLOT(insertMedia(KURL::List )));
  
  QObject::connect(Display->IA,SIGNAL(signalRemoveList(KURL::List, HDASS_ACTION_TYPE )),HDASS_PLAY_LIST,SLOT(slotReciveList(KURL::List, HDASS_ACTION_TYPE )));
  QObject::connect(Display->Media->musicFIV,SIGNAL(signalAddFileToList(KURL::List, HDASS_ACTION_TYPE )),HDASS_PLAY_LIST,SLOT(slotReciveList(KURL::List, HDASS_ACTION_TYPE )));
  
  QObject::connect(Bar->BarManagement,SIGNAL(signalManagementModeChange(int )),Display->Media,SLOT(slotChangeMode(int )));
  QObject::connect(Bar->BarManagement,SIGNAL(signalMkdir()),this,SLOT(slotKeyboardShow()));
  QObject::connect(Bar->BarManagement,SIGNAL(singalPasteFUNC_MEDIAM()),Display->Media,SLOT(slotPaste()));
  QObject::connect(Bar->BarManagement,SIGNAL(signalCutFUNC_MEDIAM()),Display->Media,SLOT(slotCut()));
  QObject::connect(Bar->BarManagement,SIGNAL(signalDeleteItem()),Display->Media,SLOT(slotDeleteItem()));
  QObject::connect(Display->Media->imgFIV,SIGNAL(signalShowTheDetialofImage(KURL )),Display->Album,SLOT(slotShowFloder(KURL )));
  
  QObject::connect(Display->Media,SIGNAL(signalImageDetial()),ControlArea,SLOT(slotShowImageDetial()));
  QObject::connect(Display->IA,SIGNAL(signalPlayItem(QString)),Bar->BarPlayer->m_player,SLOT(play(QString)));
  QObject::connect(Display->IA,SIGNAL(singalPlayItem()),Bar->BarPlayer,SLOT(slotClickFromPlayList()));
  QObject::connect(Bar->BarPlayer->m_player,SIGNAL(trackMessage(int, int, QString, QString, QString )),Display->IA,SLOT(slotHadleSongInfo(int, int, QString, QString, QString )));
  
  QObject::connect(HDASS_KEYBOARD,SIGNAL(signalEnter()),this,SLOT(slotKeyboardHide()));
  QObject::connect(HDASS_KEYBOARD,SIGNAL(signalString(QString )),this,SLOT(slotKeyboardString(QString )));
  
  QObject::connect(Display->Media,SIGNAL(signalShowKeyboard()),this,SLOT(slotKeyboardShow()));
  QObject::connect(this,SIGNAL(signalMkdir(QString )),Display->Media,SLOT(slotMkdir(QString )));
  Display->IA->ReadList();
}
void HDASS08::slotShow()
{
    this->show();
}
void HDASS08::slotKeyboardShow()
{
   //Set Disable
  
   HDASS_KEYBOARD->show();
   //Display->setEnabled(false);
   //ControlArea->setEnabled(false);
  // Bar->setEnabled(false);
}
void HDASS08::slotKeyboardHide()
{
  
  HDASS_KEYBOARD->hide();
  //Display->setEnabled(true);
  //ControlArea->setEnabled(true);
 // Bar->setEnabled(true);
  emit signalMkdir(strKeyboardString);
}
void HDASS08::slotKeyboardString(QString s)
{
  strKeyboardString=s;
  qWarning(strKeyboardString);
}


#include "hdass08.moc"
