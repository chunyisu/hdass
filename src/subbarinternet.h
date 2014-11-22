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
#ifndef SUBBARINTERNET_H
#define SUBBARINTERNET_H

#include <qwidget.h>
#include <qpixmap.h>
#include "skinbutton.h"
/**
@author sonicat
*/
class SubBarInternet : public QWidget
{
Q_OBJECT
public:
    SubBarInternet(QWidget *parent = 0, const char *name = 0);

    ~SubBarInternet();
    void xSetup();
    SkinButton *SubBarBtnInternet_Home,*SubBarBtnInternet_Previous,*SubBarBtnInternet_Next,*SubBarBtnInternet_Search;
private:
   QPixmap pixBackground;
   QPixmap *BtnGraphic[8];
};

#endif