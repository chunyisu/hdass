/***************************************************************************
 *   Copyright (C) 2004 by Karban                                          *
 *   Karban@scream01.csie.ncku.edu.tw                                      *
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
#ifndef MYBROWSER_H
#define MYBROWSER_H

#include "DownFile.h"

#include <qwidget.h>

#include <khtml_part.h> 
#include <kurl.h>

class MyBrowser : public KHTMLPart
{
Q_OBJECT
public:
    MyBrowser(QWidget *parentWidget = 0);
    ~MyBrowser();   
   
    void urlSelected (const QString &url, int button, int state, const QString &_target, KParts::URLArgs args=KParts::URLArgs());
        
    void saveHistory(const KURL &);
    void removeHistory();
    void getFile(KURL &);
        
    KURL::List history;
    KURL::List::Iterator it_history;
    DownFile *getfile;
    KURL home;
     
public:  

protected:
   
protected:   
    
public slots:
    void handleHome();
    void handleRefresh();
    void handleNext();
    void handlePrevious();
    void handleURL(const KURL &,const KParts::URLArgs &);    
    void handleCloseconnect(bool);
       
protected slots:    

signals:
    
};

#endif
