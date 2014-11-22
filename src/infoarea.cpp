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
#include "infoarea.h"
#include "sonogram.h"
#include <qvbox.h>
#include <qlabel.h>
#include <kdebug.h>
#include <qpainter.h>
InfoArea::InfoArea(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
  xSetup();
}


InfoArea::~InfoArea()
{
}

void InfoArea::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/InfoAreaBackground.png");
   setBackgroundPixmap(pixBackground);
   
   //DAVID
   m_pAnalyzer = new Sonogram( this );            
   m_pAnalyzer->setGeometry( 417,144, 338,60 );
   m_pAnalyzer->show();
   
   //DAVID Load BtnGraphic
   BtnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-VolumeUp.png");
   BtnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-VolumeUp-Active.png");
   BtnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-VolumeDown.png");
   BtnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-VolumeDown-Active.png");
   BtnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-PlayListDelete.png");
   BtnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/InfoAreaBtn-PlayListDelete-Active.png");
   //DAVID Set Volume Buttons
   IABtnVolumeUp=new SkinButton(this);
   IABtnVolumeDown=new SkinButton(this);
   IABtnPlayListDelete=new SkinButton(this);

   IABtnVolumeUp->setPixmaps(BtnGraphic[0],BtnGraphic[1]);
   IABtnVolumeUp->setGeometry(418,38,60,60);
   IABtnVolumeUp->show();
   
   IABtnVolumeDown->setPixmaps(BtnGraphic[2],BtnGraphic[3]);
   IABtnVolumeDown->setGeometry(684,349,60,60);
   IABtnVolumeDown->show();
   
   IABtnPlayListDelete->setPixmaps(BtnGraphic[4],BtnGraphic[5]);
   IABtnPlayListDelete->setGeometry(346,477,42,42);
   IABtnPlayListDelete->show();
   connect(IABtnPlayListDelete,SIGNAL(clicked()),this,SLOT(slotDeleteItems()));
   //DAVID Init PlayList Table
   InitPlayList();
   
   
}
void InfoArea::InitPlayList()
{
  PlayList=new QListView(this);
  PlayList->addColumn( "Items" );
  PlayList->setColumnWidth(0,316);
  PlayList->setRootIsDecorated( TRUE );
  PlayList->setGeometry(35,60,316,420);
  
  QFont f( "Helvetica", 12, QFont::Bold );
  PlayList->setFont( f );
  
  PlayList->show();
  connect(PlayList,SIGNAL(doubleClicked ( QListViewItem * )),this,SLOT(slotDoubleClicked(QListViewItem* )));
  ReadList();
  InitSongInfo();
  
}



void InfoArea::slotReadListFromPlayList(KURL::List playlist)
{ 
   curr_list=playlist;
   //Clear ValueList
   PlayList->clear();
   
   
   for( KURL::List::ConstIterator it = playlist.begin();it != playlist.end();it++)
   {
    //Add to value list
    qWarning((*it).fileName());
     new HDASSPlayListItem( PlayList,(*it).fileName());
   }
}

void InfoArea::ReadList()
{
      emit signalReadList();
}
void InfoArea::slotDeleteItems()
{
        KURL::List remove_list;
        int i=0;
	HDASSPlayListItem *CurChild=(HDASSPlayListItem*)PlayList->firstChild();
	for(KURL::List::ConstIterator remove_it = curr_list.begin();remove_it != curr_list.end();remove_it++,i++)
	{
		if(CurChild->isSelected ())
		
		{
			remove_list <<(*remove_it).url();
		}
		CurChild=(HDASSPlayListItem*)CurChild->nextSibling();
	}
	emit signalRemoveList(remove_list,em_remove);
}

void InfoArea::slotDoubleClicked(QListViewItem * item )
{
   HDASSPlayListItem *clickitem=(HDASSPlayListItem *)item;
   qWarning("DoubleClikced");
   emit signalPlayItem(clickitem->text(0));
   emit singalPlayItem();
 
}
void InfoArea::InitSongInfo()
{
   Artist=new QLabel(this);
   Artist->setPaletteBackgroundColor(QColor(255,255,255));
   Artist->hide();
   
   Album=new QLabel(this);
   Album->setPaletteBackgroundColor(QColor(255,255,255));
   Album->hide();
   
   BitRate=new QLabel(this);
   BitRate->setPaletteBackgroundColor(QColor(255,255,255));
   BitRate->hide();
   
   Title=new QLabel(this);
   Title->setPaletteBackgroundColor(QColor(255,255,255));
   Title->hide();
   
   
   Artist->move(420,210);
   Album->move(420,240);
   BitRate->move(420,270);
   Title->move(580,270);
   
   QFont f( "Helvetica", 14, QFont::Bold );
   
   Artist->setFont( f );
   Album->setFont( f );
   Title->setFont( f );
   BitRate->setFont( f );
   
} 
void InfoArea::ShowSongInfo(int m_length,int m_bitrate,QString m_title,QString m_artist,QString m_album)
{

}
void InfoArea::slotHadleSongInfo(int m_length,int m_bitrate,QString m_title,QString m_artist,QString m_album)
{
   QString strArtist=QString("Artist :") +(m_artist.isEmpty()?QString(" No Info"):m_artist);
   QString strTitle=(m_title.isEmpty()?QString(" No Info"):m_title);
   QString strAlbum=QString("Album :") +(m_album.isEmpty()?QString(" No Info"):m_album);
   
   QFont f( "Helvetica", 14, QFont::Bold );
   QFontMetrics fm(f);
   
   Artist->resize(fm.width(strArtist),fm.height());
   Artist->setText(strArtist);
   
   Title->move(580-fm.width(strTitle)/2,Title->y());
   Title->resize(fm.width(strTitle),fm.height());
   Title->setText(strTitle);
   
   Album->resize(fm.width(strTitle),fm.height());
   Album->setText(strAlbum);
   
   BitRate->setText(QString("BitRate : %1 ").arg(m_bitrate));
    
   //Artist->show();
  // Album->show();
   //BitRate->show();
   Title->show();

   
}

#include "infoarea.moc"
