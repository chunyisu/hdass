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

#ifndef _HDASS08_H_
#define _HDASS08_H_

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

//DAVID ---------including files---------------//
#include <qpixmap.h>
#include <kmainwindow.h>
#include "functionbar.h"
#include "function_control_area.h"


#include "displayarea.h"
#include "hdassplaylist.h"
#include "keyboard.h"
/**
 * @short Application Main Window
 * @author sonicat <is87098@cis.nctu.edu.tw>
 * @version 0.1
 */
class HDASS08 : public KMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    HDASS08();
        /**
     * Default Destructor
     */
    void xSetup();
    virtual ~HDASS08();
    
    Function_Control_Area *ControlArea;
    FunctionBar *Bar;

    DisplayArea *Display;
    hdassplaylist *HDASS_PLAY_LIST;
    keyboard *HDASS_KEYBOARD;
    QString strKeyboardString;
public slots:
    void slotShow();
    void slotKeyboardShow();
    void slotKeyboardHide();
    void slotKeyboardString(QString);
signals:
    void signalMkdir(QString);
    
private:
   QPixmap pixBackground;
};

#endif // _HDASS08_H_
