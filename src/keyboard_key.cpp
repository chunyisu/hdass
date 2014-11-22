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
#include "keyboard_key.h"
#include <qpainter.h>
//#include <qbitmap.h>
keyboard_key::keyboard_key(QWidget *parent, const char *name,QString strUpper,QString strLower,KEY_TYPE _type)
 : QPushButton(parent, name)
{
   
   key_type=_type;
   xSetup(strUpper,strLower);
}


keyboard_key::~keyboard_key()
{
}
void keyboard_key::xSetup(QString up,QString lo)
{ 
  //DAVID  set up
  pixInactive.load("/root/kde_application/hdass08/skin/keybtn.png");
  pixAcitve.load("/root/kde_application/hdass08/skin/keybtn-active.png");
  pixBackground=pixInactive;
  //QBitmap mask=QBitmap("/root/kde_application/hdass08/skin/key_btn_mask.png");
  //setMask(mask);
  resize(pixBackground.size());
  QFont serifFont( "Helvetica", 18, QFont::Bold );
  setFont(serifFont); 
  strCharUp=up;
  strCharLower=lo;
  //DAVID default is the lowercase
  upper=true;
  slotSetCase(upper);
  //setText(strCharLower);
  switch(key_type)
  {
   case KEY:
   
   connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
   break;
   
   case ENTER:
   
   connect(this,SIGNAL(clicked()),this,SLOT(slotEnter()));
   break;
   
   case BACKSPACE:
   connect(this,SIGNAL(clicked()),this,SLOT(slotBackSpace()));
   break;  
   
   case CHANGE:
   connect(this,SIGNAL(clicked()),this,SLOT(slotChange()));
   break; 
  }
  
  connect(this,SIGNAL(pressed()),this,SLOT(slotPressed()));
  connect(this,SIGNAL(released()),this,SLOT(slotReleased()));
}

void keyboard_key::slotSetCase(bool upper)
{
   if(upper)
   strCurChar=strCharUp;
   else
   strCurChar=strCharLower;
   repaint();
}

void keyboard_key::slotClicked()
{
   emit signalSendChar(strCurChar);
}

void keyboard_key::drawButton(QPainter *p)
{
  p->drawPixmap(0,0,pixBackground);
  p->drawText( rect(), AlignCenter, strCurChar );
}
void keyboard_key::slotPressed()
{
  pixBackground=pixAcitve;
  repaint();
}
void keyboard_key::slotReleased()
{
 pixBackground=pixInactive;
 repaint();
}
void keyboard_key::slotSetPixmap(QPixmap inactive,QPixmap pix_active)
{
   pixInactive=inactive;
   pixAcitve=pix_active;
   pixBackground=pixInactive;
   resize(pixBackground.size());
   repaint();
}
void keyboard_key::slotEnter()
{
  emit signalEnter();
}

void keyboard_key::slotChange()
{
  emit signalChange();
}

void keyboard_key::slotBackSpace()
{
 emit signalBackSpace();
}
#include "keyboard_key.moc"
