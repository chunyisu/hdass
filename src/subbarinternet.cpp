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
#include "subbarinternet.h"
SubBarInternet::SubBarInternet(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
    xSetup();
}


SubBarInternet::~SubBarInternet()
{
}

void SubBarInternet::xSetup()
{
   //DAVID Setup Background;
   pixBackground.load("/root/kde_application/hdass08/skin/SubBarBackground.png");
   setBackgroundPixmap(pixBackground);
   
   //DAVID Load BtnGraphic
   BtnGraphic[0]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Home.png");
   BtnGraphic[1]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Home-Active.png");
   BtnGraphic[2]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Previous.png");
   BtnGraphic[3]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Previous-Active.png");
   BtnGraphic[4]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Next.png");
   BtnGraphic[5]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Next-Active.png");
   BtnGraphic[6]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Search.png");
   BtnGraphic[7]=new QPixmap("/root/kde_application/hdass08/skin/Bar-Internet-Btn-Search-Active.png");
   
   //DAVID Internet Button
   SubBarBtnInternet_Home          =new SkinButton(this);
   SubBarBtnInternet_Previous      =new SkinButton(this);
   SubBarBtnInternet_Next            =new SkinButton(this);
   SubBarBtnInternet_Search        =new SkinButton(this);
   
   SubBarBtnInternet_Home->setPixmaps(BtnGraphic[0],BtnGraphic[1]);
   SubBarBtnInternet_Home->setGeometry(5,-1,80,80);
   SubBarBtnInternet_Home->show();
   
   SubBarBtnInternet_Previous->setPixmaps(BtnGraphic[2],BtnGraphic[3]);
   SubBarBtnInternet_Previous->setGeometry(84,0,60,80);
   SubBarBtnInternet_Previous->show();
   
   SubBarBtnInternet_Next->setPixmaps(BtnGraphic[4],BtnGraphic[5]);
   SubBarBtnInternet_Next->setGeometry(144,0,60,80);
   SubBarBtnInternet_Next->show();
   
   SubBarBtnInternet_Search->setPixmaps(BtnGraphic[6],BtnGraphic[7]);
   SubBarBtnInternet_Search->setGeometry(207,0,60,80);
   SubBarBtnInternet_Search->show();
   


  
}

#include "subbarinternet.moc"
