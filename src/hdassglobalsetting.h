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
#ifndef HDASSGLOBALSETTING_H
#define HDASSGLOBALSETTING_H

#include <qobject.h>
#include <qstring.h>
#include "enum.h"
/**
@author sonicat
*/


class HDASSGlobalSetting : public QObject
{
Q_OBJECT
public:
    HDASSGlobalSetting(QObject *parent = 0, const char *name = 0);

    ~HDASSGlobalSetting();
    void xSetup();
    void ReadingInitState();
    int intHDASS_FUNCTION_STATE;
    int intHDASS_ALBUMCLOCK_STATE;
    int intHDSS_DISPLAY_STATE;
    QString ListFileName;
};

#endif
