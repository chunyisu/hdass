/****************************************************************************
** QtFileIconDrag meta object code from reading C++ file 'qfileiconview.h'
**
** Created: Thu Apr 28 17:37:28 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.2   edited Apr 19 11:34 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../src/qfileiconview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QtFileIconDrag::className() const
{
    return "QtFileIconDrag";
}

QMetaObject *QtFileIconDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtFileIconDrag( "QtFileIconDrag", &QtFileIconDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtFileIconDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtFileIconDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtFileIconDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtFileIconDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtFileIconDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QIconDrag::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QtFileIconDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtFileIconDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QtFileIconDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtFileIconDrag" ) )
	return this;
    return QIconDrag::qt_cast( clname );
}

bool QtFileIconDrag::qt_invoke( int _id, QUObject* _o )
{
    return QIconDrag::qt_invoke(_id,_o);
}

bool QtFileIconDrag::qt_emit( int _id, QUObject* _o )
{
    return QIconDrag::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QtFileIconDrag::qt_property( int id, int f, QVariant* v)
{
    return QIconDrag::qt_property( id, f, v);
}

bool QtFileIconDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QtFileIconView::className() const
{
    return "QtFileIconView";
}

QMetaObject *QtFileIconView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QtFileIconView( "QtFileIconView", &QtFileIconView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QtFileIconView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtFileIconView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QtFileIconView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QtFileIconView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QtFileIconView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QIconView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "dir", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setDirectory", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "dir", &static_QUType_ptr, "QDir", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setDirectory", 1, param_slot_1 };
    static const QUMethod slot_2 = {"newDirectory", 0, 0 };
    static const QUMethod slot_3 = {"currentDir", 0, 0 };
    static const QUMethod slot_4 = {"slotDeletCurrItem", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "i", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"itemDoubleClicked", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "i", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_6 = {"itemClicked", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "e", &static_QUType_ptr, "QDropEvent", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<QIconDragItem>", QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotDropped", 2, param_slot_7 };
    static const QUMethod slot_8 = {"viewLarge", 0, 0 };
    static const QUMethod slot_9 = {"viewSmall", 0, 0 };
    static const QUMethod slot_10 = {"viewBottom", 0, 0 };
    static const QUMethod slot_11 = {"viewRight", 0, 0 };
    static const QUMethod slot_12 = {"flowEast", 0, 0 };
    static const QUMethod slot_13 = {"flowSouth", 0, 0 };
    static const QUMethod slot_14 = {"itemTextTruncate", 0, 0 };
    static const QUMethod slot_15 = {"itemTextWordWrap", 0, 0 };
    static const QUMethod slot_16 = {"sortAscending", 0, 0 };
    static const QUMethod slot_17 = {"sortDescending", 0, 0 };
    static const QUMethod slot_18 = {"arrangeItemsInGrid", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_19 = {"slotRightPressed", 1, param_slot_19 };
    static const QUMethod slot_20 = {"openFolder", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setDirectory(const QString&)", &slot_0, QMetaData::Public },
	{ "setDirectory(const QDir&)", &slot_1, QMetaData::Public },
	{ "newDirectory()", &slot_2, QMetaData::Public },
	{ "currentDir()", &slot_3, QMetaData::Public },
	{ "slotDeletCurrItem()", &slot_4, QMetaData::Public },
	{ "itemDoubleClicked(QIconViewItem*)", &slot_5, QMetaData::Protected },
	{ "itemClicked(QIconViewItem*)", &slot_6, QMetaData::Protected },
	{ "slotDropped(QDropEvent*,const QValueList<QIconDragItem>&)", &slot_7, QMetaData::Protected },
	{ "viewLarge()", &slot_8, QMetaData::Protected },
	{ "viewSmall()", &slot_9, QMetaData::Protected },
	{ "viewBottom()", &slot_10, QMetaData::Protected },
	{ "viewRight()", &slot_11, QMetaData::Protected },
	{ "flowEast()", &slot_12, QMetaData::Protected },
	{ "flowSouth()", &slot_13, QMetaData::Protected },
	{ "itemTextTruncate()", &slot_14, QMetaData::Protected },
	{ "itemTextWordWrap()", &slot_15, QMetaData::Protected },
	{ "sortAscending()", &slot_16, QMetaData::Protected },
	{ "sortDescending()", &slot_17, QMetaData::Protected },
	{ "arrangeItemsInGrid()", &slot_18, QMetaData::Protected },
	{ "slotRightPressed(QIconViewItem*)", &slot_19, QMetaData::Protected },
	{ "openFolder()", &slot_20, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"directoryChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "dirs", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"startReadDir", 1, param_signal_1 };
    static const QUMethod signal_2 = {"readNextDir", 0, 0 };
    static const QUMethod signal_3 = {"readDirDone", 0, 0 };
    static const QUMethod signal_4 = {"enableUp", 0, 0 };
    static const QUMethod signal_5 = {"disableUp", 0, 0 };
    static const QUMethod signal_6 = {"enableMkdir", 0, 0 };
    static const QUMethod signal_7 = {"disableMkdir", 0, 0 };
    static const QUParameter param_signal_8[] = {
	{ "list", &static_QUType_ptr, "KURL::List", QUParameter::In },
	{ "act", &static_QUType_ptr, "HDASS_ACTION_TYPE", QUParameter::In }
    };
    static const QUMethod signal_8 = {"signalAddFileToList", 2, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "url", &static_QUType_ptr, "KURL", QUParameter::In }
    };
    static const QUMethod signal_9 = {"signalShowTheDetialofImage", 1, param_signal_9 };
    static const QMetaData signal_tbl[] = {
	{ "directoryChanged(const QString&)", &signal_0, QMetaData::Public },
	{ "startReadDir(int)", &signal_1, QMetaData::Public },
	{ "readNextDir()", &signal_2, QMetaData::Public },
	{ "readDirDone()", &signal_3, QMetaData::Public },
	{ "enableUp()", &signal_4, QMetaData::Public },
	{ "disableUp()", &signal_5, QMetaData::Public },
	{ "enableMkdir()", &signal_6, QMetaData::Public },
	{ "disableMkdir()", &signal_7, QMetaData::Public },
	{ "signalAddFileToList(KURL::List,HDASS_ACTION_TYPE)", &signal_8, QMetaData::Public },
	{ "signalShowTheDetialofImage(KURL)", &signal_9, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QtFileIconView", parentObject,
	slot_tbl, 21,
	signal_tbl, 10,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QtFileIconView.setMetaObject( metaObj );
    return metaObj;
}

void* QtFileIconView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QtFileIconView" ) )
	return this;
    return QIconView::qt_cast( clname );
}

// SIGNAL directoryChanged
void QtFileIconView::directoryChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL startReadDir
void QtFileIconView::startReadDir( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL readNextDir
void QtFileIconView::readNextDir()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL readDirDone
void QtFileIconView::readDirDone()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL enableUp
void QtFileIconView::enableUp()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL disableUp
void QtFileIconView::disableUp()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL enableMkdir
void QtFileIconView::enableMkdir()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL disableMkdir
void QtFileIconView::disableMkdir()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL signalAddFileToList
void QtFileIconView::signalAddFileToList( KURL::List t0, HDASS_ACTION_TYPE t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL signalShowTheDetialofImage
void QtFileIconView::signalShowTheDetialofImage( KURL t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QtFileIconView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setDirectory((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: setDirectory((const QDir&)*((const QDir*)static_QUType_ptr.get(_o+1))); break;
    case 2: newDirectory(); break;
    case 3: currentDir(); break;
    case 4: slotDeletCurrItem(); break;
    case 5: itemDoubleClicked((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: itemClicked((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 7: slotDropped((QDropEvent*)static_QUType_ptr.get(_o+1),(const QValueList<QIconDragItem>&)*((const QValueList<QIconDragItem>*)static_QUType_ptr.get(_o+2))); break;
    case 8: viewLarge(); break;
    case 9: viewSmall(); break;
    case 10: viewBottom(); break;
    case 11: viewRight(); break;
    case 12: flowEast(); break;
    case 13: flowSouth(); break;
    case 14: itemTextTruncate(); break;
    case 15: itemTextWordWrap(); break;
    case 16: sortAscending(); break;
    case 17: sortDescending(); break;
    case 18: arrangeItemsInGrid(); break;
    case 19: slotRightPressed((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 20: openFolder(); break;
    default:
	return QIconView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QtFileIconView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: directoryChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: startReadDir((int)static_QUType_int.get(_o+1)); break;
    case 2: readNextDir(); break;
    case 3: readDirDone(); break;
    case 4: enableUp(); break;
    case 5: disableUp(); break;
    case 6: enableMkdir(); break;
    case 7: disableMkdir(); break;
    case 8: signalAddFileToList((KURL::List)(*((KURL::List*)static_QUType_ptr.get(_o+1))),(HDASS_ACTION_TYPE)(*((HDASS_ACTION_TYPE*)static_QUType_ptr.get(_o+2)))); break;
    case 9: signalShowTheDetialofImage((KURL)(*((KURL*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QIconView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QtFileIconView::qt_property( int id, int f, QVariant* v)
{
    return QIconView::qt_property( id, f, v);
}

bool QtFileIconView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
