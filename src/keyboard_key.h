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
#ifndef KEYBOARD_KEY_H
#define KEYBOARD_KEY_H

#include <qpushbutton.h>
#include <qstring.h>
#include <qpixmap.h>
/**
@author root
*/
class keyboard_key : public QPushButton
{
Q_OBJECT

public:
enum KEY_TYPE
{
  KEY,
  CHANGE,
  ENTER,
  BACKSPACE
};
    keyboard_key(QWidget *parent = 0, const char *name = 0,QString strUpper=0,QString strLower=0,KEY_TYPE _type=KEY);

    ~keyboard_key();
    void xSetup(QString u,QString l);
public slots:
   void slotSetCase(bool upper);
   void slotClicked();
   void slotPressed();
   void slotReleased();
   void slotEnter();
   void slotChange();
   void slotBackSpace();
   void slotSetPixmap(QPixmap ,QPixmap );
signals:
   void signalSendChar(QString strChar);
   void signalEnter();
   void signalChange();
   void signalBackSpace();
protected:
   void drawButton(QPainter *p);
   
private:
   QString strCurChar,strCharUp,strCharLower;
   bool upper;
   QPixmap pixBackground,pixAcitve,pixInactive;
   KEY_TYPE key_type;
};

#endif
