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
#include "subbarplayer.h"
#include <kdebug.h>
SubBarPlayer::SubBarPlayer(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
  //new Player here
  m_player=new Myplayer;
 
  slider = true;
  xSetup();
}


SubBarPlayer::~SubBarPlayer()
{
  delete m_player;
}

void SubBarPlayer::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/SubBarBackground.png");
   setBackgroundPixmap(pixBackground);
   
   //DAVID Load BtnGraphic
   BtnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Previous.png");
   BtnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Previous-Active.png");
   BtnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Play.png");
   BtnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Play-Active.png");
   BtnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Pause.png");
   BtnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Pause-Active.png");
   BtnGraphic[6]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Next.png");
   BtnGraphic[7]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Player-Btn-Next-Active.png");
  
   
   SubBtnPlayer_PlayNPause =new SkinButton(this);
   SubBtnPlayer_Backword     =new SkinButton(this);
   SubBtn_Forward                =new SkinButton(this);
   
   SubBtnPlayer_Backword->setPixmaps(BtnGraphic[0],BtnGraphic[1]);
   SubBtnPlayer_Backword->setGeometry(336,0,60,80);
   SubBtnPlayer_Backword->show();
   
   SubBtnPlayer_PlayNPause->setPixmaps(BtnGraphic[2],BtnGraphic[3]);
   SubBtnPlayer_PlayNPause->setGeometry(403,0,80,80);
   SubBtnPlayer_PlayNPause->show();
   
   SubBtn_Forward->setPixmaps(BtnGraphic[6],BtnGraphic[7]);
   SubBtn_Forward->setGeometry(484,0,60,80);
   SubBtn_Forward->show();
   
   //DAVID Pos Slider
   playerPosition = new QSlider(0,100,1,0,Qt::Horizontal,this);
   playerPosition->setGeometry( QRect(10,39,300,15) );
   //playerPosition->show();
   
   
   QObject::connect(SubBtnPlayer_PlayNPause, SIGNAL(clicked()), m_player, SLOT(play()));
   QObject::connect(SubBtnPlayer_PlayNPause,SIGNAL(clicked()),this,SLOT(ChangeBtnPlayPauseGraphic()));
   QObject::connect(SubBtn_Forward, SIGNAL(clicked()), m_player, SLOT(next()));
   QObject::connect(SubBtnPlayer_Backword, SIGNAL(clicked()), m_player, SLOT(previous()));

   state=SubBarPlayer::GO;
   
   connect(m_player, SIGNAL(positionMessage(int)), this, SLOT(handlePosition(int )));
   connect(m_player,SIGNAL(trackMessage(int, int, QString, QString, QString )),this,SLOT(handleMessage(int, int, QString, QString, QString )));
   connect(playerPosition, SIGNAL(sliderPressed()), this, SLOT(handleSliderPressed()));
   connect(playerPosition, SIGNAL(sliderReleased()), this, SLOT(handleSliderReleased()));
   
    forwardTimer = new QTimer( this ); // create internal timer
    connect( forwardTimer, SIGNAL(timeout()),this, SLOT(handleForward()) );

    
    backwardTimer = new QTimer( this );
    connect( backwardTimer, SIGNAL(timeout()), this, SLOT(handleBackward()) );
    
    slotReadList();
}

void SubBarPlayer::ChangeBtnPlayPauseGraphic()
{
  if(state==SubBarPlayer::PAUSE)
  {
    state=SubBarPlayer::GO;
    SubBtnPlayer_PlayNPause->setPixmaps(BtnGraphic[2],BtnGraphic[3]);
  }
  else
  {
    state=SubBarPlayer::PAUSE;
    SubBtnPlayer_PlayNPause->setPixmaps(BtnGraphic[4],BtnGraphic[5]);
  }
}

void SubBarPlayer::insertMedia(KURL::List list)
{
     
     m_player->add(list);
     m_player->handleRepeat(true);
     kdDebug() << "[playercontrol]insertMedia "<< endl; 
     
}

void SubBarPlayer::removeMedia( KURL::List remove_list)
{
     m_player->removeMedia(remove_list); 
}
void SubBarPlayer::initMedia(KURL::List list)
{
	m_player->initlist(list);
	m_player->handleRepeat(false);
	kdDebug() << "[playercontrol]initMedia "<< endl; 
}


void SubBarPlayer::handlePosition(int position)
{

     if(slider)playerPosition->setValue(position);    
}

void SubBarPlayer::handleVolume(int volume)
{
}

void SubBarPlayer::handleSliderReleased()
{
     m_player->handleSlider(playerPosition->value());
     slider = true;   
}

void SubBarPlayer::handleSliderPressed()
{
     slider = false;
}

void SubBarPlayer::handleNextPressed()
{
     kdDebug() << "Next Pressed"<< endl;
     forwardTimer->start( 100 );
     slider = false;
     
}

void SubBarPlayer::handleNextReleased()
{
     kdDebug() << "Next Released" << endl;
     forwardTimer->stop();
     m_player->handleSlider(playerPosition->value());
     slider = true;
}

void SubBarPlayer::handleForward()
{
     kdDebug() << "[UI::handleForward]" << endl;
     int fast = playerPosition->value();
     fast++;
     playerPosition->setValue(fast);
//     Pos->setNum(fast);
}

void SubBarPlayer::handlePreviousPressed()
{
     kdDebug() << "Previous Pressed"<< endl;
     backwardTimer->start( 100 );
     slider = false;
}

void SubBarPlayer::handlePreviousReleased()
{
     kdDebug() << "Previous Released" << endl;
     backwardTimer->stop();
     m_player->handleSlider(playerPosition->value());
     slider = true;
}

void SubBarPlayer::handleBackward()
{
     kdDebug() << "[UI::handleBackward]" << endl;
     int fast = playerPosition->value();
     fast--;
     playerPosition->setValue(fast);
}

void SubBarPlayer::handleMessage(int m_length,int m_bitrate,QString m_title,QString m_artist,QString m_album)
{
	playerPosition->setMaxValue(m_length);
}

void SubBarPlayer::slotReceivePL(KURL::List list)
{
  receive_list=list;
}
 
void SubBarPlayer::slotReadList()
{
   emit signalRequestPL();
  //insertMedia(receive_list);
}
void SubBarPlayer::slotClickFromPlayList()
{
  state=SubBarPlayer::GO;
  ChangeBtnPlayPauseGraphic();
}
#include "subbarplayer.moc"
