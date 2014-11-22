/***************************************************************************
                          kstartuplogo.h  -  description
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


#ifndef KSTARTUPLOGO_H
#define KSTARTUPLOGO_H

//DAVID -----------Including files ----------------
#include <qtimer.h>
#include <qwidget.h>

/**
  *@author 
  */

class KStartupLogo : public QWidget  {
   Q_OBJECT

public:
	KStartupLogo(QWidget *parent=0, const char *name=0);
	~KStartupLogo();

	void setHideEnabled(bool bEnabled) { m_bReadyToHide = bEnabled; };
public slots:
        void slotCloseLogo();
signals:
        void signalTriggerMainWidget();
protected:
	virtual void mousePressEvent( QMouseEvent*);
	bool m_bReadyToHide;
	QTimer *LogoCloseTimer;
	int LogoCloseTime;
};

#endif
