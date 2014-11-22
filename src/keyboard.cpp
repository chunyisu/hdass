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
#include "keyboard.h"
#define KEYNUMS 41

int KeyPos[KEYNUMS][2]=
    {
     {60,64},//1
     {120,64},//2
     {180,64},//3
     {240,64},//4
     {300,64},//5
     {360,64},//6
     {420,64},//7
     {480,64},//8
     {540,64},//9
     {600,64},//0
     {31,123},//Q
     {0,0},//W
     {0,0},//E
     {0,0},//R
     {0,0},//T
     {0,0},//Y
     {0,0},//U
     {0,0},//I
     {0,0},//O
     {0,0},//P
     {60,177},//A
     {0,0},//S
     {0,0},//D
     {0,0},//F
     {0,0},//G
     {0,0},//H
     {0,0},//J
     {0,0},//K
     {0,0},//L
     {85,232},//Z
     {0,0},//X
     {0,0},//C
     {0,0},//V
     {0,0},//B
     {0,0},//N
     {0,0},//M
     {0,0},//,
     {122,290},//SAPCE
     {440,290},//CHANGE BUTTON
     {551,238},//ENTER
     {556,14},//BACK
    };
keyboard::keyboard(QWidget *parent, const char *name)
 : QWidget(parent, name),strString(0)
{
 xSEtup();
}


keyboard::~keyboard()
{
}
void keyboard::xSEtup()
{
  //DAVID Set Background
  pixBackground.load("/root/kde_application/hdass08/skin/KeyBoardBackground.png");
  setBackgroundPixmap(pixBackground);
  pixMask=QBitmap("/root/kde_application/hdass08/skin/KeyBoardMask.png");
  setMask(pixMask);
  resize(pixBackground.size());
  InitKey();
  upper=false;
}
void keyboard::slotReceiveChar(QString str_char)
{
  strString=strString+str_char;
  Label->setText(strString);
}

void keyboard::slotSendString()
{
  emit signalString(strString);
}

void keyboard::slotClearStr()
{
 strString=QString();
}
void keyboard::InitKey()
{
   int keypos=0;
   int width=58;
   
   //1->0
   key_1=new keyboard_key(this,"A_a","1","!");
   key_1->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   key_1->show();
   key_list.append(key_1);
   connect(key_1,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   keypos++;
   
   key_2=new keyboard_key(this,"A_a","2","@");
   key_2->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   key_2->show();
   key_list.append(key_2);
   connect(key_2,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   keypos++;
   
   key_3=new keyboard_key(this,"A_a","3","#");
   key_3->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_3,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_3->show();
   key_list.append(key_3);
   keypos++;
   
   key_4=new keyboard_key(this,"A_a","4","$");
   key_4->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_4,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_4->show();
   key_list.append(key_4);
   keypos++;
   
   key_5=new keyboard_key(this,"A_a","5","%");
   key_5->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   key_5->show();
   key_list.append(key_5);
   connect(key_5,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   keypos++;
   
   key_6=new keyboard_key(this,"A_a","6","^");
   key_6->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_6,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_6->show();
   key_list.append(key_6);
   keypos++;
   
   key_7=new keyboard_key(this,"A_a","7","&");
   key_7->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_7,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_7->show();
   key_list.append(key_7);
   keypos++;
   
   key_8=new keyboard_key(this,"A_a","8","*");
   key_8->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_8,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_8->show();
   key_list.append(key_8);
   keypos++;
   
   key_9=new keyboard_key(this,"A_a","9","(");
   key_9->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_9,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_9->show();
   key_list.append(key_9);
   keypos++;
   
   key_0=new keyboard_key(this,"A_a","0",")");
   key_0->move(KeyPos[0][0]+width*keypos,KeyPos[0][1]);
   connect(key_0,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_0->show();
   key_list.append(key_0);
   keypos++;
   
   
   /////////////////////////////////////////////////////////////////////////////
   //Q->P
   
   keypos=0;
   
   key_q=new keyboard_key(this,"A_a","Q","q");
   key_q->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_q,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_q->show();
   key_list.append(key_q);
   keypos++;
   
   key_w=new keyboard_key(this,"A_a","W","w");
   key_w->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_w,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_w->show();
   key_list.append(key_w);
   keypos++;
   
   key_e=new keyboard_key(this,"A_a","E","e");
   key_e->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_e,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_e->show();
   key_list.append(key_e);
   keypos++;
   
   key_r=new keyboard_key(this,"A_a","R","r");
   key_r->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_r,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_r->show();
   key_list.append(key_r);
   keypos++;
   
   key_t=new keyboard_key(this,"A_a","T","t");
   key_t->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_t,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_t->show();
   key_list.append(key_t);
   keypos++;
   
   key_y=new keyboard_key(this,"A_a","Y","y");
   key_y->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_y,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_y->show();
   key_list.append(key_y);
   keypos++;
   
   key_u=new keyboard_key(this,"A_a","U","u");
   key_u->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_u,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_u->show();
   key_list.append(key_u);
   keypos++;
   
   key_i=new keyboard_key(this,"A_a","I","i");
   key_i->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_i,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_i->show();
   key_list.append(key_i);
   keypos++;
   
   key_o=new keyboard_key(this,"A_a","O","o");
   key_o->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_o,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_o->show();
   key_list.append(key_o);
   keypos++;
   
   key_p=new keyboard_key(this,"A_a","P","p");
   key_p->move(KeyPos[10][0]+width*keypos,KeyPos[10][1]);
   connect(key_p,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_p->show();
   key_list.append(key_p);
   keypos++;
   
   ///////////////////////////////////////////////////////////////////////////
   //A->L
   keypos=0;
   
   key_a=new keyboard_key(this,"A_a","A","a");
   key_a->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_a,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_a->show();
   key_list.append(key_a);
   keypos++;
   
   key_s=new keyboard_key(this,"A_a","S","s");
   key_s->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_s,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_s->show();
   key_list.append(key_s);
   keypos++;
   
   key_d=new keyboard_key(this,"A_a","D","d");
   key_d->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_d,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_d->show();
   key_list.append(key_d);
   keypos++;
   
   key_f=new keyboard_key(this,"A_a","F","f");
   key_f->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_f,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_f->show();
   key_list.append(key_d);
   keypos++;
   
   key_g=new keyboard_key(this,"A_a","G","g");
   key_g->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_g,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_g->show();
   key_list.append(key_g);
   keypos++;
   
   key_h=new keyboard_key(this,"A_a","H","h");
   key_h->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_h,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_h->show();
   key_list.append(key_h);
   keypos++;
   
   key_j=new keyboard_key(this,"A_a","J","j");
   key_j->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_j,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_j->show();
   key_list.append(key_j);
   keypos++;
   
   key_k=new keyboard_key(this,"A_a","K","k");
   key_k->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_k,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_k->show();
   key_list.append(key_k);
   keypos++;
   
   key_l=new keyboard_key(this,"A_a","L","l");
   key_l->move(KeyPos[20][0]+width*keypos,KeyPos[20][1]);
   connect(key_l,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_l->show();
   key_list.append(key_l);
   keypos++;
   
   ////////////////////////////////////////////////////////////////////////////
   // Z->COMMA
   keypos=0;
   
   key_z=new keyboard_key(this,"A_a","Z","z");
   key_z->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_z,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_z->show();
   key_list.append(key_z);
   keypos++;
   
   key_x=new keyboard_key(this,"A_a","X","x");
   key_x->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_x,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_x->show();
   key_list.append(key_x);
   keypos++;
   
   key_c=new keyboard_key(this,"A_a","C","c");
   key_c->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_c,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_c->show();
   key_list.append(key_c);
   keypos++;
   
   key_v=new keyboard_key(this,"A_a","V","v");
   key_v->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_v,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_v->show();
   key_list.append(key_v);
   keypos++;
   
   key_b=new keyboard_key(this,"A_a","B","b");
   key_b->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_b,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_b->show();
   key_list.append(key_b);
   keypos++;
   
   key_n=new keyboard_key(this,"A_a","N","n");
   key_n->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_n,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_n->show();
   key_list.append(key_n);
   keypos++;
   
   key_m=new keyboard_key(this,"A_a","M","m");
   key_m->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_m,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_m->show();
   key_list.append(key_m);
   keypos++;
   
   key_comma=new keyboard_key(this,"A_a",",",".");
   key_comma->move(KeyPos[29][0]+width*keypos,KeyPos[29][1]);
   connect(key_comma,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_comma->show();
   key_list.append(key_comma);
   keypos++;
   
   
   //SPACE 
   QPixmap pixSpace=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Space.png");
   QPixmap pixSpaceAcitve=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Space-Active.png");
   key_space=new keyboard_key(this,"A_a"," "," ");
   key_space->move(KeyPos[37][0],KeyPos[37][1]);
   key_space->slotSetPixmap(pixSpace,pixSpaceAcitve);
   connect(key_space,SIGNAL(signalSendChar(QString )),this,SLOT(slotReceiveChar(QString )));
   key_space->show();
   
   //CHANGE
   QPixmap pixChange=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Change.png");
   QPixmap pixChangeActive=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Change-Active.png");
   key_change=new keyboard_key(this,"A_a","","",keyboard_key::CHANGE);
   key_change->move(KeyPos[38][0],KeyPos[38][1]);
   key_change->slotSetPixmap(pixChange,pixChangeActive);
   connect(key_change,SIGNAL(signalChange()),this,SLOT(slotChange()));
   key_change->show();
   
   //ENTER
   QPixmap pixEnter=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Enter.png");
   QPixmap pixEnterAcitve=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-Enter-Active.png");
   key_enter=new keyboard_key(this,"A_a","","",keyboard_key::ENTER);
   key_enter->move(KeyPos[39][0],KeyPos[39][1]);
   key_enter->slotSetPixmap(pixEnter,pixEnterAcitve);
   connect(key_enter,SIGNAL(signalEnter()),this,SLOT(slotEnter()));
   key_enter->show();
   
   
   //BACKSPACE
   QPixmap pixBackSpace=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-BackSpace.png");
   QPixmap pixBackSpaceActive=QPixmap("/root/kde_application/hdass08/skin/KeyBoardKey-BackSpace-Active.png");
   key_backspace=new keyboard_key(this,"A_a","","",keyboard_key::BACKSPACE);
   key_backspace->move(KeyPos[40][0],KeyPos[40][1]);
   key_backspace->slotSetPixmap(pixBackSpace,pixBackSpaceActive);
   connect(key_backspace,SIGNAL(signalBackSpace()),this,SLOT(slotBackSpace()));
   key_backspace->show();
   
   //String Label
   //QPixmap pixLabel=QPixmap("/root/kde_application/hdass08/skin/KeyBoardLabel.png");
   Label=new QLabel(this);
   Label->setPaletteBackgroundColor(QColor(203,244,254));
   Label->resize(400,28);
   //Label->setPixmap(pixLabel);
   Label->move(88,17);
   QFont f( "Helvetica", 16, QFont::Bold );
   Label->setFont( f );
   Label->setAlignment(Qt::AlignCenter);
  // Label->setText("HAHAA");
   Label->show();

}

void keyboard::slotBackSpace()
{
 if(!strString.isEmpty())
 {
   qWarning("BackSpace");
   strString.truncate(strString.length()-1);
   Label->setText(strString);
 }
 
}
void keyboard::slotEnter()
{
    qWarning("Enter");
    emit signalString(strString);
    emit signalEnter();
    slotClearStr();
    
}

void keyboard::slotChange()
{
    qWarning("change");
    keyboard_key *indexkey;
    //DAVID Change the uppercase/lowercase;
    if(upper)
    upper=false;
    else
    upper=true;
     
    for(indexkey=key_list.first();indexkey;indexkey=key_list.next())
    {
      indexkey->slotSetCase(upper);
    }
}
#include "keyboard.moc"
