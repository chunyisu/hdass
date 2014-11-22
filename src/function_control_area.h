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
#ifndef FUNCTION_CONTROL_AREA_H
#define FUNCTION_CONTROL_AREA_H
//DAVID ---including files---
#include <qpixmap.h>
#include "skinbutton.h"
#include "global_define.h"
#include <qobject.h>

/**
@author sonicat
*/
class Function_Control_Area : public QWidget
{
Q_OBJECT
public:
    Function_Control_Area(QWidget *parent = 0, const char *name = 0);
    //DAVID InitWidget();
    void xSetup();
    ~Function_Control_Area();
    SkinButton *fun_btn_internet,*fun_btn_player,*fun_btn_management,*fun_btn_albumclock,*fun_btn_setting,*fun_btn_close,*fun_btn_imagedetial;//6 btn item
public slots:
   void slotProcessChangeFunc();
   void slotChangeButton(int);
   void slotImageDetial();
   void slotShowImageDetial();
signals:
  void signalChangeFunc(int);
  void signalBackToManagement();
private:
   QPixmap *btnGraphic[14];
   QPixmap pixBackground;
};

#endif
