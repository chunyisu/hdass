/***************************************************************************
                           kstartuplogo.cpp  -  description
                             -------------------
    artwork              : KDevelop Project / Ralf Nolden <nolden@kde.org>
    begin                : Mon Oct 1 2001
    copyright            : (C) 2001 by Kai Heitkamp
    email                : koncd@kai-heitkamp.de 
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "kstartuplogo.h"
#include <kapplication.h>
#include <kstandarddirs.h>

KStartupLogo::KStartupLogo(QWidget * parent, const char *name) : QWidget(parent,name, WStyle_NoBorder | WStyle_Customize | WDestructiveClose ), m_bReadyToHide( false ),LogoCloseTimer(NULL),LogoCloseTime(1){
	QPixmap pm;
	pm.load("/root/kde_application/hdass08/skin/skin-logo.jpg");
	setBackgroundPixmap(pm);
	setGeometry(KApplication::desktop()->width()/2-pm.width()/2, KApplication::desktop()->height()/2-pm.height()/2, pm.width(),pm.height());
	
	//DAVID Timer Set up
	LogoCloseTimer=new QTimer(this);
	//DAVID Connect LogoCloseTimer to slot "slotCloseLogo"
	connect(LogoCloseTimer,SIGNAL(timeout()),this,SLOT(slotCloseLogo()));
	LogoCloseTimer->start( LogoCloseTime*1000, TRUE ); // 2 seconds single-shot timer
}

KStartupLogo::~KStartupLogo()
{
}

void KStartupLogo::mousePressEvent( QMouseEvent*)
{
	if (m_bReadyToHide) hide();
}

void KStartupLogo::slotCloseLogo()
{
   //DAVID Hide Logo itself.
   this->hide();
   emit signalTriggerMainWidget();
}

#include "kstartuplogo.moc"
