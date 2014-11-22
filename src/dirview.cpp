/****************************************************************************
** $Id: qt/dirview.cpp   3.3.2   edited Oct 28 15:44 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "dirview.h"

#include <qdir.h>
#include <qfile.h>
#include <qfileinfo.h>
#include <qpixmap.h>
#include <qevent.h>
#include <qpoint.h>
#include <qmessagebox.h>
#include <qdragobject.h>
#include <qmime.h>
#include <qstrlist.h>
#include <qstringlist.h>
#include <qapplication.h>
#include <qheader.h>
#include <kdebug.h>
#include <qurl.h>
#include <kio/job.h>



static const char * folder_locked[]={
    "16 16 10 1",
    "h c #808080",
    "b c #ffa858",
    "f c #c0c0c0",
    "e c #c05800",
    "# c #000000",
    "c c #ffdca8",
    ". c None",
    "a c #585858",
    "g c #a0a0a4",
    "d c #ffffff",
    "..#a#...........",
    ".#abc####.......",
    ".#daa#eee#......",
    ".#ddf#e##b#.....",
    ".#dfd#e#bcb##...",
    ".#fdccc#daaab#..",
    ".#dfbbbccgfg#ba.",
    ".#ffb#ebbfgg#ba.",
    ".#ffbbe#bggg#ba.",
    ".#fffbbebggg#ba.",
    ".##hf#ebbggg#ba.",
    "...###e#gggg#ba.",
    ".....#e#gggg#ba.",
    "......###ggg#b##",
    ".........##g#b##",
    "...........####."};

static const char * pix_file []={
    "16 16 7 1",
    "# c #000000",
    "b c #ffffff",
    "e c #000000",
    "d c #404000",
    "c c #c0c000",
    "a c #ffffc0",
    ". c None",
    "................",
    ".........#......",
    "......#.#a##....",
    ".....#b#bbba##..",
    "....#b#bbbabbb#.",
    "...#b#bba##bb#..",
    "..#b#abb#bb##...",
    ".#a#aab#bbbab##.",
    "#a#aaa#bcbbbbbb#",
    "#ccdc#bcbbcbbb#.",
    ".##c#bcbbcabb#..",
    "...#acbacbbbe...",
    "..#aaaacaba#....",
    "...##aaaaa#.....",
    ".....##aa#......",
    ".......##......."};

QPixmap *folderLocked = 0;
QPixmap *folderClosed = 0;
QPixmap *folderOpen = 0;
QPixmap *fileNormal = 0;

/*****************************************************************************
 *
 * Class Directory
 *
 *****************************************************************************/

Directory::Directory( Directory * parent, const QString& filename )
    : QListViewItem( parent ), f(filename),
      showDirsOnly( parent->showDirsOnly ),
      pix( 0 )
{
    
    p = parent;
    readable = QDir( fullName() ).isReadable();

    if ( !readable )
	setPixmap( folderLocked );
    else
	setPixmap( folderClosed );
}


Directory::Directory( QListView * parent, const QString& filename )
    : QListViewItem( parent ), f(filename),
      showDirsOnly( ( (DirectoryView*)parent )->showDirsOnly() ),
      pix( 0 )
{
    p = 0;// no parent Directory 
    readable = QDir( fullName() ).isReadable();

}


void Directory::setPixmap( QPixmap *px )
{
    pix = px;
    setup();
    widthChanged( 0 );
    invalidateHeight();
    repaint();
}


const QPixmap *Directory::pixmap( int i ) const
{
    if ( i )
	return 0;
    return pix;
}

void Directory::setOpen( bool o )
{
    if ( o )
	setPixmap( folderOpen );
    else
	setPixmap( folderClosed );

    if ( o && !childCount() ) 
    {
	QString s( fullName() );
	QDir thisDir( s );
	if ( !thisDir.isReadable() ) 
	{
	    readable = FALSE;
	    setExpandable( FALSE );
	    return;
	}

	listView()->setUpdatesEnabled( FALSE );
	const QFileInfoList * files = thisDir.entryInfoList();
	if ( files ) {
	    QFileInfoListIterator it( *files );
	    QFileInfo * fi;
	    while( (fi=it.current()) != 0 ) {
		++it;
		if ( fi->fileName() == "." || fi->fileName() == ".." )
		    ; // nothing
		else if ( fi->isSymLink() && !showDirsOnly ) {
		    FileItem *item = new FileItem( this, fi->fileName(),
						     "Symbolic Link" );
		    item->setPixmap( fileNormal );
		}
		else if ( fi->isDir() )
		{
		    (void)new Directory( this, fi->fileName() );
		}
		else if ( !showDirsOnly ) {
		    FileItem *item
			= new FileItem( this, fi->fileName(),
					     fi->isFile()?"File":"Special" );
		    item->setPixmap( fileNormal );
		}
	    }
	}
	listView()->setUpdatesEnabled( TRUE );
    }
    QListViewItem::setOpen( o );
}


void Directory::setup()
{
    setExpandable( TRUE );
    QListViewItem::setup();
}


QString Directory::fullName()
{
    QString s;
    if ( p ) {
	s = p->fullName();
	s.append( f.name() );
	s.append( "/" );
    } else {
	s = f.name();
    }
    return s;
}


QString Directory::text( int column ) const
{
    if ( column == 0 )
	return f.name();
    else if ( readable )
	return "Directory";
    else
	return "Unreadable Directory";
}
void Directory::Mkdir(QString s)
{
 	QDir currDir=QDir( fullName() );
 	qWarning(fullName());
	//DAVID need modified
	currDir.mkdir(s);
	new Directory(this,s);
}
/*****************************************************************************
 *
 * Class DirectoryView
 *
 *****************************************************************************/

DirectoryView::DirectoryView( QWidget *parent, const char *name, bool sdo )
    : QListView( parent, name ), dirsOnly( sdo ), oldCurrent( 0 ),
      dropItem( 0 ), mousePressed( FALSE )
{
    autoopen_timer = new QTimer( this );
    if ( !folderLocked ) {
	folderLocked = new QPixmap( folder_locked );
	folderClosed = new QPixmap( "/root/kde_application/hdass08/skin/folder_sound.png" );
	folderOpen = new QPixmap( "/root/kde_application/hdass08/skin/folder_sound.png" );
	fileNormal = new QPixmap( pix_file );
    }

    connect( this, SIGNAL( doubleClicked( QListViewItem * ) ),
	     this, SLOT( slotFolderSelected( QListViewItem * ) ) );
    connect( this, SIGNAL( returnPressed( QListViewItem * ) ),
	     this, SLOT( slotFolderSelected( QListViewItem * ) ) );

    setAcceptDrops( TRUE );
    viewport()->setAcceptDrops( TRUE );

    connect( autoopen_timer, SIGNAL( timeout() ),
	     this, SLOT( openFolder() ) );
}

void DirectoryView::slotFolderSelected( QListViewItem *i )
{
    if ( !i || !showDirsOnly() )
	return;

    Directory *dir = (Directory*)i;
    emit folderSelected( dir->fullName() );
}

void DirectoryView::openFolder()
{
    autoopen_timer->stop();
    if ( dropItem && !dropItem->isOpen() ) {
	dropItem->setOpen( TRUE );
	dropItem->repaint();
    }
}

static const int autoopenTime = 750;


void DirectoryView::contentsDragEnterEvent( QDragEnterEvent *e )
{
    if ( !QUriDrag::canDecode(e) ) {
	e->ignore();
	return;
    }

    oldCurrent = currentItem();

    QListViewItem *i = itemAt( contentsToViewport(e->pos()) );
    if ( i ) {
	dropItem = i;
	autoopen_timer->start( autoopenTime );
    }
    
}


void DirectoryView::contentsDragMoveEvent( QDragMoveEvent *e )
{
    if ( !QUriDrag::canDecode(e) ) {
	e->ignore();
	return;
    }

    QPoint vp = contentsToViewport( ( (QDragMoveEvent*)e )->pos() );
    QListViewItem *i = itemAt( vp );
    
    if ( i ) {
	setSelected( i, TRUE );
	e->accept();
	if ( i != dropItem ) {
	    autoopen_timer->stop();
	    dropItem = i;
	    autoopen_timer->start( autoopenTime );
	}
	switch ( e->action() ) {
	case QDropEvent::Copy:
	    break;
	case QDropEvent::Move:
	    e->acceptAction();
	    break;
	case QDropEvent::Link:
	    e->acceptAction();
	    break;
	default:
	    ;
	}
    } else {
	e->ignore();
	autoopen_timer->stop();
	dropItem = 0;
    }
}

void DirectoryView::contentsDragLeaveEvent( QDragLeaveEvent * )
{
    autoopen_timer->stop();
    dropItem = 0;

    setCurrentItem( oldCurrent );
    setSelected( oldCurrent, TRUE );
}

void DirectoryView::contentsDropEvent( QDropEvent *e )
{
    autoopen_timer->stop();

    if ( !QUriDrag::canDecode(e) ) {
	e->ignore();
	return;
    }

    QListViewItem *item = itemAt( contentsToViewport(e->pos()) );
    
    if(item)
    {
    	//DAVID make a list to receive the dropping objects
    	QStrList lst;
	
	//DAVID decode the objects data to list
	QUriDrag::decode( e, lst );
	
	QString DirName=QDir::convertSeparators(fullPath(item));

	for ( uint i = 0; i < lst.count(); ++i ) 
	
	{
		
		//kdDebug()<<lst.at(i);
		//DAVID get the dropping object name
	    	QString fullpathfilename = QDir::convertSeparators(QUriDrag::uriToLocalFile(lst.at(i)));
		QUrl url(fullpathfilename);
		QString filename=url.fileName();
		QString distfilename=DirName+QString("/")+filename;
		//copy file
		KIO::copy(KURL(fullpathfilename),KURL(distfilename),false);
	}
	
    }
    else
    {
     e->ignore();
    }

}


QString DirectoryView::fullPath(QListViewItem* item)
{
    QString fullpath = item->text(0);
    while ( (item=item->parent()) ) {
	if ( item->parent() )
	    fullpath = item->text(0) + "/" + fullpath;
	else
	    fullpath = item->text(0) + fullpath;
    }
#ifdef Q_WS_WIN
	if (fullpath.length() > 2 && fullpath[1] != ':') {
		QDir dir(fullpath);
		fullpath = dir.currentDirPath().left(2) + fullpath;
	}
#endif
	
    return fullpath;
}

void DirectoryView::contentsMousePressEvent( QMouseEvent* e )
{
    QListView::contentsMousePressEvent(e);
    QPoint p( contentsToViewport( e->pos() ) );
    QListViewItem *i = itemAt( p );
    if ( i ) {
	// if the user clicked into the root decoration of the item, don't try to start a drag!
	if ( p.x() > header()->cellPos( header()->mapToActual( 0 ) ) +
	     treeStepSize() * ( i->depth() + ( rootIsDecorated() ? 1 : 0) ) + itemMargin() ||
	     p.x() < header()->cellPos( header()->mapToActual( 0 ) ) ) {
	    presspos = e->pos();
	    mousePressed = TRUE;
	}
    }
}

void DirectoryView::contentsMouseMoveEvent( QMouseEvent* e )
{
    if ( mousePressed && ( presspos - e->pos() ).manhattanLength() > QApplication::startDragDistance() ) {
	mousePressed = FALSE;
	QListViewItem *item = itemAt( contentsToViewport(presspos) );
	if ( item ) {
	    QString source = fullPath(item);
	    if ( QFile::exists(source) ) {
		QUriDrag* ud = new QUriDrag(viewport());
		ud->setFileNames( source );
		if ( ud->drag() )
		    QMessageBox::information( this, "Drag source",
		    QString("Delete ") + QDir::convertSeparators(source), "Not implemented" );
	    }
	}
    }
}

void DirectoryView::contentsMouseReleaseEvent( QMouseEvent * )
{
    mousePressed = FALSE;
}

void DirectoryView::setDir( const QString &s )
{
    QListViewItemIterator it( this );
    ++it;
    for ( ; it.current(); ++it ) {
	it.current()->setOpen( FALSE );
    }

    QStringList lst( QStringList::split( "/", s ) );
    QListViewItem *item = firstChild();
    QStringList::Iterator it2 = lst.begin();
    for ( ; it2 != lst.end(); ++it2 ) {
	while ( item ) {
	    if ( item->text( 0 ) == *it2 ) {
		item->setOpen( TRUE );
		break;
	    }
	    item = item->itemBelow();
	}
    }

    if ( item )
	setCurrentItem( item );
}

void FileItem::setPixmap( QPixmap *p )
{
    pix = p;
    setup();
    widthChanged( 0 );
    invalidateHeight();
    repaint();
}


const QPixmap *FileItem::pixmap( int i ) const
{
    if ( i )
	return 0;
    return pix;
}

