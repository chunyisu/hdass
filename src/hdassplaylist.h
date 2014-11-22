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
#ifndef HDASSPLAYLIST_H
#define HDASSPLAYLIST_H

#include <qobject.h>
#include <kurl.h>
#include <qstring.h>
#include <qfile.h>
#include "enum.h"
/**
@author sonicat
*/
class hdassplaylist : public QObject
{
Q_OBJECT

public:
    hdassplaylist(QObject *parent = 0, const char *name = 0);

    ~hdassplaylist();
    QFile *List;
    KURL::List url_list,url_list_cut_buffer;
    void xSetup();
    void ReadListFile(QString FileName);
public slots:
   void slotPLRequest();
   void slotReciveList(KURL::List list,HDASS_ACTION_TYPE act);
signals:
   void signalPLSend(KURL::List);
private:
  void RemoveList(KURL::List);
  void CutList(KURL::List);
  void PasteList();
  void SaveList();
  void AppendList(KURL::List);    
};

#endif
