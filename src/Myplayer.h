/***************************************************************************
                        Myplayer.h  -  description
                            -------------------
    begin                : 7-19 2004
    copyright            : (C) 2004 by Karban
    email                :
***************************************************************************/

/***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/
 
#ifndef MYPLAYER_H
#define MYPLAYER_H

#include "metabundle.h"
#include "analyzerbase.h"

#include <qwidget.h> 
#include <kurl.h>

class Myplayer : public QWidget
{
Q_OBJECT
enum PLAYSTATE
{
 Idle,Pause,Go
};
public:
  Myplayer();
  ~Myplayer();
  
  void handleMessage(const MetaBundle &);

public slots:
  void play();
  void play(QString FileName);
  void pause();
  void stop();
  void next();
  void previous();
  
  void increase_volume();
  void decrease_volume();
  void setVolume(int);
      
  void handleNext();
  void handlePrevious();
  void handlePosition(int);
  void handleRepeat(bool);
  void handleRandom(bool);
  void handleSlider(int);
  void handlePlayItem(KURL &);    
  void initlist(KURL::List &);
  void add(KURL::List &); 
  void clearMedia();
  void removeMedia(KURL::List &);

signals:
  void trackMessage(int,int,QString,QString,QString);
  void volumeMessage(int);
  void positionMessage(int);
  
private: 
  void savePlaylist();
  void restorePlaylist();
  
  KURL::List m_list;
  KURL::List::Iterator it;
  int m_Vol;
  bool m_repeat;
  bool m_random;
  PLAYSTATE state;
};

#endif
