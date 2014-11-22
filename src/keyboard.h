/***************************************************************************
 *   Copyright (C) 2005 by root                                            *
 *   root@colicoli.linux                                                   *
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
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <qwidget.h>
#include <qstring.h>
#include "keyboard_key.h"
#include <qpixmap.h>
#include <qbitmap.h>
#include <stdio.h> 
#include <stdlib.h>
#include <qlabel.h>
#include <qptrlist.h>
/**
@author root
*/

class keyboard : public QWidget
{
Q_OBJECT
public:
    keyboard(QWidget *parent = 0, const char *name = 0);

    ~keyboard();
    void xSEtup();
    QString  strString;
public slots:
    void slotReceiveChar(QString str_char);
    void slotSendString();
    void slotClearStr();
    void slotEnter();
    void slotBackSpace();
    void slotChange();
signals:
    void signalString(QString);
    void signalEnter();
private :
    keyboard_key *key_a,*key_b,*key_c,*key_d,*key_e,*key_f,*key_g,*key_h,*key_i,*key_j,*key_k,*key_l,*key_m,*key_n,*key_o,*key_p,*key_q,*key_r,*key_s,*key_t,*key_u,*key_v,*key_w,*key_x,*key_y,*key_z,*key_1,*key_2,*key_3,*key_4,*key_5,*key_6,*key_7,*key_8,*key_9,*key_0,*key_comma,*key_space,*key_enter,*key_change,*key_backspace;
    QPixmap pixBackground ;
    QBitmap pixMask;
    void InitKey();
    QLabel *Label;
    bool upper;
    QPtrList<keyboard_key> key_list;
    
};

#endif
