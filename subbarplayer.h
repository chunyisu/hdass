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
#ifndef SUBBARPLAYER_H
#define SUBBARPLAYER_H

#include <qvariant.h>
#include <qslider.h>
#include <qtimer.h>
#include <qwidget.h>
#include "skinbutton.h"
#include <qpushbutton.h>
#include <kurl.h>
#include <qwidget.h>
#include <qpixmap.h>

#include "skinbutton.h"
#include "Myplayer.h"
#include "analyzerbase.h"
/**
@author sonicat
*/
class SubBarPlayer : public QWidget
{

enum PLAYSTATE{PAUSE,GO};
Q_OBJECT
public:
    SubBarPlayer(QWidget *parent = 0, const char *name = 0);

    ~SubBarPlayer();
    void xSetup();
    QWidget *m_pAnalyzer;
    QSlider *playerPosition;
    QTimer *forwardTimer;
    QTimer *backwardTimer;
    Myplayer *m_player;
    KURL::List receive_list;  
    SkinButton *SubBtnPlayer_PlayNPause,*SubBtnPlayer_Backword,*SubBtn_Forward,*testBtn;

private:
   QPixmap pixBackground;
   QPixmap *BtnGraphic[8];
   PLAYSTATE state;
   bool slider; 

public slots:
    void handlePosition(int);
    void handleVolume(int);
    void handleSliderReleased();
    void handleSliderPressed();
    void handleNextPressed();
    void handleNextReleased();
    void handlePreviousPressed();
    void handlePreviousReleased();
    void handleForward();
    void handleBackward();
    void handleMessage(int m_length,int m_bitrate,QString m_title,QString m_artist,QString m_album); 
    void insertMedia(KURL::List list);
    void removeMedia(KURL::List remove_list);  
    void initMedia(KURL::List list);
    void ChangeBtnPlayPauseGraphic();
    void slotReceivePL(KURL::List list);
    void slotReadList();
    void slotClickFromPlayList();
signals:
    void signalRequestPL();

};

#endif
