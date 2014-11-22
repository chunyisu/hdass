/****************************************************************************
** $Id: qt/qfileiconview.cpp   3.3.2   edited Nov 18 10:39 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "qfileiconview.h"
#include <qpainter.h>
#include <qstringlist.h>
#include <qpixmap.h>
#include <qmime.h>
#include <qstrlist.h>
#include <qdragobject.h>
#include <qmessagebox.h>
#include <qevent.h>
#include <qpopupmenu.h>
#include <qcursor.h>
#include <qapplication.h>
#include <qwmatrix.h>
#include <math.h>
#include <stdlib.h>
#include <kdebug.h>

static QPixmap *iconFileLarge = 0;
QPixmap *ArrayImage[100];
static void cleanup()
{
    
    delete iconFileLarge;
    iconFileLarge = 0;
    
}

/*****************************************************************************
 *
 * Class QtFileIconDrag
 *
 *****************************************************************************/

QtFileIconDrag::QtFileIconDrag( QWidget * dragSource, const char* name )
    : QIconDrag( dragSource, name )
{
}

const char* QtFileIconDrag::format( int i ) const
{
    if ( i == 0 )
	return "application/x-qiconlist";
    else if ( i == 1 )
	return "text/uri-list";
    else
	return 0;
}

QByteArray QtFileIconDrag::encodedData( const char* mime ) const
{
    QByteArray a;
    if ( QString( mime ) == "application/x-qiconlist" ) {
	a = QIconDrag::encodedData( mime );
    } else if ( QString( mime ) == "text/uri-list" ) {
	QString s = urls.join( "\r\n" );
	a.resize( s.length() );
	memcpy( a.data(), s.latin1(), s.length() );
    }
    return a;
}

bool QtFileIconDrag::canDecode( QMimeSource* e )
{
    return e->provides( "application/x-qiconlist" ) ||
	e->provides( "text/uri-list" );
}

void QtFileIconDrag::append( const QIconDragItem &item, const QRect &pr,
			     const QRect &tr, const QString &url )
{
    QIconDrag::append( item, pr, tr );
    QString ourUrl = url;    
#ifdef Q_WS_WIN
    if (ourUrl.length() > 2 && ourUrl[1] != ':') {
	QDir dir(ourUrl);
	ourUrl = dir.absPath();
    }
#endif
    urls << QUriDrag::localFileToUri(ourUrl);
}

/*****************************************************************************
 *
 * Class QtFileIconViewItem
 *
 *****************************************************************************/

QtFileIconViewItem::QtFileIconViewItem( QtFileIconView *parent, QFileInfo *fi ,int pixindex)
    : QIconViewItem( parent, fi->fileName() ), itemFileName( fi->filePath() ),PixIndex(pixindex),
      itemFileInfo( fi ), checkSetText( FALSE )
{
    vm = QtFileIconView::Large;//view mode

   if ( itemFileInfo->isFile() )
    {
    	if(fi->extension()=="jpg"||fi->extension()=="png"||fi->extension()=="bmp"||fi->extension()=="jpeg")
	itemType=Image;
	else if(fi->extension()=="mp3")
	{
	itemType = File;//MP3 File
	}
    }

    checkSetText = TRUE;

    QObject::connect( &timer, SIGNAL( timeout() ), iconView(), SLOT( openFolder() ) );
	if(itemType==Image)
	{
		 if(ArrayImage[PixIndex])
		 {
		 	delete ArrayImage[PixIndex];
		 }
		 img=QPixmap(itemFileName);
  		ArrayImage[PixIndex]=addBorder(&img,1);
		setPixmap(*ArrayImage[PixIndex]);
  	}
}
void QtFileIconViewItem::paintItem( QPainter *p, const QColorGroup &cg )
{
    if ( itemFileInfo->isSymLink() ) {
	QFont f( p->font() );
	f.setItalic( TRUE );
	p->setFont( f );
    }
    QIconViewItem::paintItem( p, cg );
}

void QtFileIconViewItem::viewModeChanged( QtFileIconView::ViewMode m )
{
    vm = m;
    setDropEnabled( itemType == Dir && QDir( itemFileName ).isReadable() );
    calcRect();
}

QPixmap *QtFileIconViewItem::pixmap() const
{
    switch ( itemType ) 
    {
   
   	case Image:
   	{
		return ArrayImage[PixIndex];
   	}
    	default:
	{
		return iconFileLarge;
	}
    }
}

QtFileIconViewItem::~QtFileIconViewItem()
{
    delete itemFileInfo;
}

void QtFileIconViewItem::setText( const QString &text )
{
    if ( checkSetText ) {
	if ( text == "." || text == "." || text.isEmpty() )
	    return;
	QDir dir( itemFileInfo->dir() );
	if ( dir.rename( itemFileInfo->fileName(), text ) ) {
	    itemFileName = itemFileInfo->dirPath( TRUE ) + "/" + text;
	    delete itemFileInfo;
	    itemFileInfo = new QFileInfo( itemFileName );
	    QIconViewItem::setText( text );
	}
    } else {
	QIconViewItem::setText( text );
    }
}

QPixmap* addBorder(QPixmap *pix, bool hasAlpha)
{
	//DAVID Read Background
	QPixmap	pbgxpm=QPixmap("/root/kde_application/hdass08/skin/bgxpm.png");
	//DAVID Read Boarder Image
	QImage ptop=QImage("/root/kde_application/hdass08/skin/border.png");
	
	//DAVID New a QPixmap res with size pix->size()
	QPixmap res(pix->size());
	
	//Draw it on painter
	QPainter p(&res);
		if(hasAlpha) 
			p.drawTiledPixmap (0, 0, pix->width(), pix->height(),pbgxpm);
		//DAVID draw broder to painter		
		p.drawImage(0, 0, ptop.scale(pix->width(), pix->height()));
		p.drawImage((int)floor((float)pix->width()/ptop.width()*14),
			(int)floor((float)pix->height()/ptop.height()*13),
			pix->convertToImage().smoothScale(
				(int)ceil(pix->width()*0.79738562092),
				(int)ceil(pix->height()*0.76691729323)));
	p.end();
	QImage a=res.convertToImage().scale(70,70);
	QPixmap *temp=new QPixmap(a);
	return temp;
}
bool QtFileIconViewItem::acceptDrop( const QMimeSource *e ) const
{
    if ( type() == Dir && e->provides( "text/uri-list" ) &&
	 dropEnabled() )
	return TRUE;

    return FALSE;
}

void QtFileIconViewItem::dropped( QDropEvent *e, const QValueList<QIconDragItem> & )
{
    timer.stop();

    if ( !QUriDrag::canDecode( e ) ) {
	e->ignore();
	return;
    }

    QStringList lst;
    QUriDrag::decodeLocalFiles( e, lst );

    QString str;
    if ( e->action() == QDropEvent::Copy )
	str = "Copy\n\n";
    else
	str = "Move\n\n";
    for ( uint i = 0; i < lst.count(); ++i )
	str += QString( "   %1\n" ).arg( lst[i] );
    str += QString( "\n"
	"To\n\n"
	"	%1" ).arg( filename() );

    QMessageBox::information( iconView(), e->action() == QDropEvent::Copy ? "Copy" : "Move" , str, "Not Implemented" );
    if ( e->action() == QDropEvent::Move )
	QMessageBox::information( iconView(), "Remove" , str, "Not Implemented" );
    e->acceptAction();
}

void QtFileIconViewItem::dragEntered()
{
    if ( type() != Dir ||
	 type() == Dir && !QDir( itemFileName ).isReadable() )
	return;

    ( (QtFileIconView*)iconView() )->setOpenItem( this );
    timer.start( 1500 );
}

void QtFileIconViewItem::dragLeft()
{
    if ( type() != Dir ||
	 type() == Dir && !QDir( itemFileName ).isReadable() )
	return;

    timer.stop();
}

/*****************************************************************************
 *
 * Class QtFileIconView
 *
 *****************************************************************************/

QtFileIconView::QtFileIconView( const QString &dir, QWidget *parent, const char *name,FloderType type )
    : QIconView( parent, name ), viewDir( dir ), newFolderNum( 0 ),flodertype(type)
{
   
	qAddPostRoutine( cleanup );
	//MP3 File Icon
	iconFileLarge = new QPixmap( "/root/kde_application/hdass08/skin/mp3icon.png" );
        vm = Large;

    setGridX( 75 );
    setGridY( 75 );
    setResizeMode( Adjust );
    setWordWrapIconText( FALSE );

    connect( this, SIGNAL( doubleClicked( QIconViewItem * ) ),
	     this, SLOT( itemDoubleClicked( QIconViewItem * ) ) );
    connect( this, SIGNAL( returnPressed( QIconViewItem * ) ),
	     this, SLOT( itemDoubleClicked( QIconViewItem * ) ) );
    connect( this, SIGNAL( dropped( QDropEvent *, const QValueList<QIconDragItem> & ) ),
	     this, SLOT( slotDropped( QDropEvent *, const QValueList<QIconDragItem> & ) ) );
    connect( this, SIGNAL( contextMenuRequested( QIconViewItem *, const QPoint & ) ),
	     this, SLOT( slotRightPressed( QIconViewItem * ) ) );
    connect(this,SIGNAL(clicked( QIconViewItem *)),this,SLOT(itemClicked(QIconViewItem* ))); 
    setHScrollBarMode( AlwaysOff );
    setVScrollBarMode( Auto );

    setAutoArrange( TRUE );
    setSorting( TRUE );
    openItem = 0;
}

void QtFileIconView::openFolder()
{
    if ( !openItem )
	return;
    if ( openItem->type() != QtFileIconViewItem::Dir ||
	 openItem->type() == QtFileIconViewItem::Dir &&
	 !QDir( openItem->itemFileName ).isReadable() )
	return;

    openItem->timer.stop();
    setDirectory( openItem->itemFileName );
}

void QtFileIconView::setDirectory( const QString &dir )
{
    viewDir = QDir( dir );
    readDir( viewDir );
}

void QtFileIconView::setDirectory( const QDir &dir )
{
    viewDir = dir;
    readDir( viewDir );
}

void QtFileIconView::newDirectory()
{
    setAutoArrange( FALSE );
    selectAll( FALSE );
    if ( viewDir.mkdir( QString( "New Folder %1" ).arg( ++newFolderNum ) ) ) 
    {                                                                        
	QFileInfo *fi = new QFileInfo( viewDir, QString( "New Folder %1" ).arg( newFolderNum ) );
	QtFileIconViewItem *item = new QtFileIconViewItem( this, new QFileInfo( *fi ) ,0);
	item->setKey( QString( "000000%1" ).arg( fi->fileName() ) );
	delete fi;
	repaintContents( contentsX(), contentsY(), contentsWidth(), contentsHeight(), FALSE );
	ensureItemVisible( item );
	item->setSelected( TRUE, TRUE );
	setCurrentItem( item );
	repaintItem( item );
	qApp->processEvents();
	item->rename();
    }
    setAutoArrange( TRUE );
}

QDir QtFileIconView::currentDir()
{
    return viewDir;
}

static bool isRoot( const QString &s )
{
#if defined(Q_OS_UNIX)
    if ( s == "/" )
	return TRUE;
#elif defined(Q_OS_WIN32)
    QString p = s;
    if ( p.length() == 3 &&
	 p.right( 2 ) == ":/" )
	return TRUE;
    if ( p[ 0 ] == '/' && p[ 1 ] == '/' ) {
	int slashes = p.contains( '/' );
	if ( slashes <= 3 )
	    return TRUE;
	if ( slashes == 4 && p[ (int)p.length() - 1 ] == '/' )
	    return TRUE;
    }
#endif

    return FALSE;
}

void QtFileIconView::readDir( const QDir &dir )
{
   QDir s=dir;
   if(flodertype==Image)
   {
   	s.setNameFilter("*.jpg");
   }
   else if(flodertype==Music)
   {
   	s.setNameFilter("*.mp3");
   }
   if ( !dir.isReadable() )
	return;

    if ( isRoot( dir.absPath() ) )
	emit disableUp();
    else
	emit enableUp();

    clear();

    emit directoryChanged( s.absPath() );

    const QFileInfoList *filist = s.entryInfoList( QDir::Files );

    emit startReadDir( filist->count() );

    int pixindex=0;
    QFileInfoListIterator it( *filist );
    QFileInfo *fi;
    bool allowRename = FALSE, allowRenameSet = FALSE;
    while ( ( fi = it.current() ) != 0 ) {
        
	++it;
	if ( fi && fi->fileName() == ".." && ( fi->dirPath() == "/" || fi->dirPath().isEmpty() ) )
	    continue;
	emit readNextDir();
	QtFileIconViewItem *item = new QtFileIconViewItem( this, new QFileInfo( *fi ),pixindex );
	if ( fi->isDir() )
	    item->setKey( QString( "000000%1" ).arg( fi->fileName() ) );
	else
	    item->setKey( fi->fileName() );
	if ( !allowRenameSet ) {
	    if ( !QFileInfo( fi->absFilePath() ).isWritable() ||
		 item->text() == "." || item->text() == ".." )
		allowRename = FALSE;
	    else
		allowRename = TRUE;
	    if ( item->text() == "." || item->text() == ".." )
		allowRenameSet = FALSE;
	    else
		allowRenameSet = TRUE;
	}
	item->setRenameEnabled( allowRename );
	++pixindex;
    }

    if ( !QFileInfo( s.absPath() ).isWritable() )
	emit disableMkdir();
    else
	emit enableMkdir();

    emit readDirDone();
}

void QtFileIconView::itemDoubleClicked( QIconViewItem *i )
{
    //qWarning("DAVID Test for itemDoubleClicked!!");
    QtFileIconViewItem *item = ( QtFileIconViewItem* )i;
    if ( item->type() == QtFileIconViewItem::Dir ) 
    {
	viewDir = QDir( item->filename() );
	readDir( viewDir );
    } 
    else if ( item->type() == QtFileIconViewItem::Link && QFileInfo( QFileInfo( item->filename() ).readLink() ).isDir() ) 
    {
	viewDir = QDir( QFileInfo( item->filename() ).readLink() );
	readDir( viewDir );
    }
    
    //DAVID  If double clicked ,then send the file item to the playlist.
    
    //DAVID Check that if the file type,u just need to send mp3 file to the playlist.
    else if(item->type()==QtFileIconViewItem::File)//MP3 file
    {
    	//DAVID send the file path to the playlist.
	kdDebug()<<item->filename();
	KURL url(QString("file:")+item->filename());
	qWarning(url.fileName());
	KURL::List list;
	list<<url;
	emit signalAddFileToList(list,mm_append);
    }
    else if(item->type()==QtFileIconViewItem::Image)//Image file
    {
    	//DAVID Show the detail of Image
	kdDebug()<<item->filename();
	KURL url(QString("file:")+item->filename());
	emit signalShowTheDetialofImage(url);
    }
    
}

QDragObject *QtFileIconView::dragObject()
{

    if ( !currentItem() )
	return 0;

    QPoint orig = viewportToContents( viewport()->mapFromGlobal( QCursor::pos() ) );
    QtFileIconDrag *drag = new QtFileIconDrag( viewport() );
    drag->setPixmap( *currentItem()->pixmap(),
		     QPoint( currentItem()->pixmapRect().width() / 2, currentItem()->pixmapRect().height() / 2 ) );
    for ( QtFileIconViewItem *item = (QtFileIconViewItem*)firstItem(); item;
	  item = (QtFileIconViewItem*)item->nextItem() ) {
	if ( item->isSelected() ) {
	    QIconDragItem id;
	    id.setData( QCString( item->filename() ) );
	    drag->append( id,
			  QRect( item->pixmapRect( FALSE ).x() - orig.x(),
				 item->pixmapRect( FALSE ).y() - orig.y(),
				 item->pixmapRect().width(), item->pixmapRect().height() ),
			  QRect( item->textRect( FALSE ).x() - orig.x(),
				 item->textRect( FALSE ).y() - orig.y(),
				 item->textRect().width(), item->textRect().height() ),
			  QString( item->filename() ) );
	}
    }
    return drag;
}

void QtFileIconView::keyPressEvent( QKeyEvent *e )
{
    if ( e->key() == Key_N &&
	 ( e->state() & ControlButton ) )
	newDirectory();
    else
	QIconView::keyPressEvent( e );
}

void QtFileIconView::slotDropped( QDropEvent *e, const QValueList<QIconDragItem> & )
{
    if ( openItem )
	openItem->timer.stop();
    if ( !QUriDrag::canDecode( e ) ) {
	e->ignore();
	return;
    }

    QStringList lst;
    QUriDrag::decodeLocalFiles( e, lst );

    QString str;
    if ( e->action() == QDropEvent::Copy )
	str = "Copy\n\n";
    else
	str = "Move\n\n";
    for ( uint i = 0; i < lst.count(); ++i )
	str += QString( "   %1\n" ).arg( QDir::convertSeparators(lst[i]) );
    str += QString( "\n"
	"To\n\n"
	"	%1" ).arg( viewDir.absPath() );

    QMessageBox::information( this, e->action() == QDropEvent::Copy ? "Copy" : "Move" , str, "Not Implemented" );
    if ( e->action() == QDropEvent::Move )
	QMessageBox::information( this, "Remove" , QDir::convertSeparators(lst.join("\n")), "Not Implemented" );
    e->acceptAction();
    openItem = 0;
}

void QtFileIconView::viewLarge()
{
    setViewMode( Large );
}

void QtFileIconView::viewSmall()
{
    setViewMode( Small );
}

void QtFileIconView::viewBottom()
{
    setItemTextPos( Bottom );
}

void QtFileIconView::viewRight()
{
    setItemTextPos( Right );
}

void QtFileIconView::flowEast()
{
    setHScrollBarMode( AlwaysOff );
    setVScrollBarMode( Auto );
    setArrangement( LeftToRight );
}

void QtFileIconView::flowSouth()
{
    setVScrollBarMode( AlwaysOff );
    setHScrollBarMode( Auto );
    setArrangement( TopToBottom );
}

void QtFileIconView::sortAscending()
{
    sort( TRUE );
}

void QtFileIconView::sortDescending()
{
    sort( FALSE );
}

void QtFileIconView::itemTextTruncate()
{
    setWordWrapIconText( FALSE );
}

void QtFileIconView::itemTextWordWrap()
{
    setWordWrapIconText( TRUE );
}

void QtFileIconView::slotRightPressed( QIconViewItem *item )
{
    if ( !item ) { // right pressed on viewport
	QPopupMenu menu( this );

	menu.insertItem( "&Large view", this, SLOT( viewLarge() ) );
	menu.insertItem( "&Small view", this, SLOT( viewSmall() ) );
	menu.insertSeparator();
	menu.insertItem( "Text at the &bottom", this, SLOT( viewBottom() ) );
	menu.insertItem( "Text at the &right", this, SLOT( viewRight() ) );
	menu.insertSeparator();
	menu.insertItem( "Arrange l&eft to right", this, SLOT( flowEast() ) );
	menu.insertItem( "Arrange t&op to bottom", this, SLOT( flowSouth() ) );
	menu.insertSeparator();
	menu.insertItem( "&Truncate item text", this, SLOT( itemTextTruncate() ) );
	menu.insertItem( "&Wordwrap item text", this, SLOT( itemTextWordWrap() ) );
	menu.insertSeparator();
	menu.insertItem( "Arrange items in &grid", this, SLOT( arrangeItemsInGrid() ) );
	menu.insertSeparator();
	menu.insertItem( "Sort &ascending", this, SLOT( sortAscending() ) );
	menu.insertItem( "Sort &descending", this, SLOT( sortDescending() ) );

	menu.setMouseTracking( TRUE );
	menu.exec( QCursor::pos() );
    } else { // on item
	QPopupMenu menu( this );

	int RENAME_ITEM = menu.insertItem( "Rename Item" );
	int REMOVE_ITEM = menu.insertItem( "Remove Item" );

	menu.setMouseTracking( TRUE );
	int id = menu.exec( QCursor::pos() );

	if ( id == -1 )
	    return;

	if ( id == RENAME_ITEM && item->renameEnabled() ) {
	    item->rename();
	} else if ( id == REMOVE_ITEM ) {
	    delete item;
	    QMessageBox::information( this, "Not implemented!", "Deleting files not implemented yet,\n"
				      "The item has only been removed from the view! " );
	}
    }
}

void QtFileIconView::setViewMode( ViewMode m )
{
    if ( m == vm )
	return;

    vm = m;
    QtFileIconViewItem *item = (QtFileIconViewItem*)firstItem();
    for ( ; item; item = (QtFileIconViewItem*)item->nextItem() )
	item->viewModeChanged( vm );

    arrangeItemsInGrid();
}
void QtFileIconView::slotDeletCurrItem()
{

 QtFileIconViewItem *item=( QtFileIconViewItem* )firstItem();
 while(item)
 {
 	if(item->isSelected())
	{
		QFile deletefile(item->filename());
		deletefile.remove();
		QtFileIconViewItem *curitem=item;
		item=( QtFileIconViewItem* )item->nextItem();
		delete curitem;
	}
	else
	{
		item=( QtFileIconViewItem* )item->nextItem();
	}
 }
 sort();
}
void QtFileIconView::itemClicked(QIconViewItem *i)
{
  QtFileIconViewItem *item = ( QtFileIconViewItem* )i;
  setCurrentItem(i);
  //qWarning(item->filename());
}