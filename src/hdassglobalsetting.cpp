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
#include "hdassglobalsetting.h"

HDASSGlobalSetting::HDASSGlobalSetting(QObject *parent, const char *name)
 : QObject(parent, name)
{
   xSetup();
}


HDASSGlobalSetting::~HDASSGlobalSetting()
{
}

void HDASSGlobalSetting::xSetup()
{
  ReadingInitState();
}

void HDASSGlobalSetting::ReadingInitState()
{
  //init  all needed here
  intHDASS_FUNCTION_STATE=em_internet;
  intHDASS_ALBUMCLOCK_STATE=em_album;
  intHDSS_DISPLAY_STATE=em_display_internet;
  //read from file
  ListFileName=QString("PlayList.pls");
}

#include "hdassglobalsetting.moc"
