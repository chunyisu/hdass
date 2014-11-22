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
#include "hdassclock.h"
#include <qpainter.h>
#include <qbitmap.h>
#include <kdebug.h>
hdassClock::hdassClock(QWidget *parent, const char *name)
 : QWidget(parent, name)
{
   xSetup();
}


hdassClock::~hdassClock()
{

}

void hdassClock::xSetup()
{
    time = QTime::currentTime();		// get current time
    internalTimer = new QTimer( this );	// create internal timer
    connect( internalTimer, SIGNAL(timeout()), SLOT(timeout()) );
    internalTimer->start( 5000 );		// emit signal every 5 seconds
    
    //DAVID Setbackgorund
    pixBackground.load("/root/kde_application/hdass08/skin/ClockBackground.png");
    setBackgroundPixmap(pixBackground);
    
}

void hdassClock::setTime(const QTime & t)
{
  time = t;
    disconnect( internalTimer, SIGNAL(timeout()), this, SLOT(timeout()) );
    if (autoMask())
	updateMask();
    else
	update();
 
}

void hdassClock::timeout()
{
    QTime old_time = time;
    time = QTime::currentTime();
    if ( old_time.minute() != time.minute() 
	|| old_time.hour() != time.hour() ) {	// minute or hour has changed
	if (autoMask())
	    updateMask();
	else
	    update();
    }
}

void hdassClock::paintEvent(QPaintEvent *)
{
    if ( autoMask() )
	return;
    QPainter paint( this );
    paint.setBrush( colorGroup().foreground() );
    drawClock( &paint );
}

void hdassClock::updateMask()
{
   QBitmap bm( size() );
    //bm.fill( color0 );			//transparent

    QPainter paint;
    paint.begin( &bm, this );
    QBrush brush=QBrush(white);
    brush.setStyle(SolidPattern); 
    paint.setBrush( brush );		// use non-transparent color
    paint.setPen(color1);

    drawClock( &paint );

    paint.end();
    setMask( bm );
}

void hdassClock::drawClock( QPainter *paint )
{
    paint->setPen(Qt::white);
    paint->save();
    
    paint->setWindow( -500,-500, 1000,1000 );

    QRect v = paint->viewport();
    int d = QMIN( v.width(), v.height() );
    paint->setViewport( v.left() + (v.width()-d)/2,v.top() + (v.height()-d)/2, d, d );
    QPointArray pts;

    paint->save();
    
    paint->rotate( 30*(time.hour()%12-3) + time.minute()/2 ); 
    QPixmap hr;
    hr.load("/root/kde_application/hdass08/skin/hdassClockArrowHr.png"); 
    paint->drawPixmap(0,(hr.height()/2)-100,hr);
    paint->restore();

    paint->save();
    paint->rotate( (time.minute()-15)*6 );
    QPixmap min;
    min.load("/root/kde_application/hdass08/skin/hdassClockArrowMin.png");
    paint->drawPixmap(0,(min.height()/2)-90,min);
    paint->restore();
}

#include "hdassclock.moc"
