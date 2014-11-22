/***************************************************************************
 *   Copyright (C) 2004 by root                                            *
 *   root@colicoli                                                         *
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
#ifndef HDASSCLOCK_H
#define HDASSCLOCK_H

#include <qwidget.h>
#include <qdatetime.h>
#include <qtimer.h>
#include <qpixmap.h>
/**
@author root
*/
class QTimer;
class hdassClock : public QWidget
{
Q_OBJECT
public:
    hdassClock(QWidget *parent = 0, const char *name = 0);
    void xSetup();
    ~hdassClock();
    
protected:
    void updateMask();
    void paintEvent( QPaintEvent *);
  //  void mousePressEvent( QMouseEvent *);
  //  void mouseMoveEvent( QMouseEvent *);
    void drawClock( QPainter* );
    
private slots:
    void timeout();

public slots:
    void setTime( const QTime & t );

private:
    QPoint clickPos;
    QTime time;
    QTimer *internalTimer;
    QPixmap pixBackground;
};

#endif
