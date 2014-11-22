# set the include path for X, qt and KDE
INCLUDES = \
        -I$(kde_includes)/arts \
        -I$(kde_includes)/taglib \
        -I$(kde_includes)/kparts \
        $(all_includes)
# these are the headers for your project


# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/hdass08.pot

KDE_ICON = hdass08

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = hdass08

# the application source, library search path, and link libraries

hdass08_LDFLAGS = $(KDE_RPATH) $(all_libraries)
hdass08_LDADD = $(LIB_KDEUI) \
           -lqtmcop -lkmedia2_idl -lartsflow \
           -lsoundserver_idl -lartskde -lartsgui \
           -lartsgui_kde -lartsmodules -ltag -lkparts -lkhtml
# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = hdass08.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/hdass08
shellrc_DATA = hdass08ui.rc

noinst_HEADERS = amarokarts.h amarokconfig.h analyzerbase.h artsengine.h dirview.h displayarea.h DownFile.h enginebase.h enginecontroller.h engineobserver.h enum.h fht.h functionbar.h function_control_area.h global_define.h hdass08.h hdassalbum.h hdassclock.h hdassglobalsetting.h hdassimagedetial.h hdassplaylist.h imagedetial.h infoarea.h kstartuplogo.h main.h mediamanagement.h metabundle.h MyBrowser.h Myplayer.h qfileiconview.h skinbutton.h sonogram.h subbarclose.h subbarinternet.h subbarmanagement.h subbarsetting.h subbaralbumclock.h hdassplaylistitem.h subbarplayer.h plugin.h pluginmanager.h keyboard_key.h keyboard.h
hdass08_SOURCES = amarokarts.cc amarokconfig.cpp analyzerbase.cpp artsengine.cpp dirview.cpp displayarea.cpp DownFile.cpp enginebase.cpp enginecontroller.cpp engineobserver.cpp fht.cpp functionbar.cpp function_control_area.cpp hdass08.cpp hdassalbum.cpp hdassclock.cpp hdassglobalsetting.cpp hdassimagedetial.cpp hdassplaylist.cpp imagedetial.cpp infoarea.cpp kstartuplogo.cpp main.cpp mediamanagement.cpp metabundle.cpp MyBrowser.cpp Myplayer.cpp qfileiconview.cpp skinbutton.cpp sonogram.cpp subbarclose.cpp subbarinternet.cpp subbarmanagement.cpp subbarsetting.cpp subbaralbumclock.cpp hdassplaylistitem.cpp subbarplayer.cpp plugin.cpp pluginmanager.cpp keyboard_key.cpp keyboard.cpp
