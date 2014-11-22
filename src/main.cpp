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

//DAVID -----------Including files ----------------
#include "hdass08.h"
#include "kstartuplogo.h"
#include "global_define.h"

//DAVID ----------- end---------------------------


#include <kapplication.h>
#include <kaboutdata.h>
#include <kcmdlineargs.h>
#include <klocale.h>
int intHDASS_FUNCTION_STATE;
HDASSGlobalSetting GlobalSetting;
static const char description[] =
    I18N_NOOP("A KDE KPart Application");

static const char version[] = "0.1";

static KCmdLineOptions options[] =
{
//    { "+[URL]", I18N_NOOP( "Document to open." ), 0 },
    KCmdLineLastOption
};

void HDASS_INIT()
{
  intHDASS_FUNCTION_STATE=em_internet;
}
int main(int argc, char **argv)
{
    KAboutData about("hdass08", I18N_NOOP("HDASS08"), version, description,
                     KAboutData::License_GPL, "(C) 2005 sonicat", 0, 0, "is87098@cis.nctu.edu.tw");
    about.addAuthor( "sonicat", 0, "is87098@cis.nctu.edu.tw" );
    KCmdLineArgs::init(argc, argv, &about);
    KCmdLineArgs::addCmdLineOptions( options );
    KApplication app;
    HDASS08 *mainWin = 0;

    if (app.isRestored())
    {
        RESTORE(HDASS08);
    }
    else
    {
        // no session.. just start up normally
        KCmdLineArgs *args = KCmdLineArgs::parsedArgs();

        //DAVID HDASS Logo Init Here//
	KStartupLogo* HDASS_logo=NULL;
	HDASS_logo = new KStartupLogo();
	HDASS_logo->show();
	
	//Init All HDASS Setting 
	HDASS_INIT();
	
        mainWin = new HDASS08();
	mainWin->setGeometry(0,0,800,600);
	
	//DAVID this connection let HDASS_logo to trigger the mainWin
	QObject::connect(HDASS_logo,SIGNAL(signalTriggerMainWidget()),mainWin,SLOT(slotShow()));
	
 
        //mainWin->show();
         
        args->clear();
    }

    // mainWin has WDestructiveClose flag by default, so it will delete itself.
    return app.exec();
}

