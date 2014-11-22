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
#ifndef INFOAREA_H
#define INFOAREA_H

#include <qwidget.h>
#include <qpixmap.h>
#include <kurl.h>
#include <qlistview.h>
#include <qvaluelist.h>
#include <qlabel.h>
#include "skinbutton.h"
#include "global_define.h"
#include "hdassplaylistitem.h"
#include "hdassplaylist.h"
#include "enum.h"
/**
@author sonicat
*/

class InfoArea : public QWidget
{
Q_OBJECT
public:
    InfoArea(QWidget *parent = 0, const char *name = 0);
    void xSetup();
    ~InfoArea();
    SkinButton *IABtnVolumeUp,*IABtnVolumeDown,*IABtnPlayListDelete;
    QWidget *m_pAnalyzer;
    QListView * PlayList;
    // QValueList<HDASSPlayListItem *> CurrItemList;
    KURL::List curr_list;
public slots:
  void slotReadListFromPlayList(KURL::List playlist);
  void ReadList();
  void slotDeleteItems();
  void slotDoubleClicked(QListViewItem * item );
  void slotHadleSongInfo(int,int,QString,QString,QString); 
signals:
 void signalReadList();
 void signalRemoveList(KURL::List removelist,HDASS_ACTION_TYPE action);
 void signalPlayItem(QString FileName);
 void singalPlayItem();  
private:
   QPixmap pixBackground;
   QPixmap *BtnGraphic[6];
   QLabel  *Artist,*Album,*Length,*Year,*Title,*BitRate;
   void InitPlayList();  
   void InitSongInfo();
   void ShowSongInfo(int m_length,int m_bitrate,QString m_title,QString m_artist,QString m_album);
};

#endif
