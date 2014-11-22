/****************************************************************************
** SkinButton meta object code from reading C++ file 'skinbutton.h'
**
** Created: Tue Apr 26 22:11:49 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.2   edited Apr 19 11:34 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../src/skinbutton.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *SkinButton::className() const
{
    return "SkinButton";
}

QMetaObject *SkinButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_SkinButton( "SkinButton", &SkinButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString SkinButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkinButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString SkinButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "SkinButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* SkinButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButton::staticMetaObject();
    static const QUMethod slot_0 = {"slotPressed", 0, 0 };
    static const QUMethod slot_1 = {"slotReleased", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotPressed()", &slot_0, QMetaData::Protected },
	{ "slotReleased()", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"SkinButton", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_SkinButton.setMetaObject( metaObj );
    return metaObj;
}

void* SkinButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "SkinButton" ) )
	return this;
    return QButton::qt_cast( clname );
}

bool SkinButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotPressed(); break;
    case 1: slotReleased(); break;
    default:
	return QButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool SkinButton::qt_emit( int _id, QUObject* _o )
{
    return QButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool SkinButton::qt_property( int id, int f, QVariant* v)
{
    return QButton::qt_property( id, f, v);
}

bool SkinButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
