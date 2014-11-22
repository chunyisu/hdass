/***************************************************************************
                      artsengine.h  -  aRts audio interface
                         -------------------
begin                : Dec 31 2003
copyright            : (C) 2003 by Mark Kretschmann
email                : markey@web.de
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef AMAROK_ARTSENGINE_H
#define AMAROK_ARTSENGINE_H

#include "amarokarts.h" 
#include "enginebase.h"

#include <vector>

#include <qguardedptr.h>
#include <qmap.h>
#include <qstringlist.h>
#include <qwidget.h>

#include <arts/artsgui.h>
#include <arts/soundserver.h>

//#include <arts/kartswidget.h>
//#include <arts/kplayobjectfactory.h>

class QStringList;
class QTimer;
class QTimerEvent;

class KArtsDispatcher;
class KArtsWidget;
class KURL;


namespace KDE { class PlayObject; }


class ArtsEngine : public EngineBase
{
    Q_OBJECT

    public:
                                                 ArtsEngine( );
                                                 ~ArtsEngine();
                                        
        void                                     init( bool& restart, int scopeSize, bool restoreEffects ); 
                                                                                                  
        bool                                     initMixer( bool hardware );
        bool                                     canDecode( const KURL &url, mode_t mode, mode_t permissions );
        StreamingMode                            streamingMode() { return Socket; }
        long                                     position() const;
        EngineBase::EngineState                  state() const;
        bool                                     isStream() const;

        std::vector<float>*                      scope();

        QStringList                              availableEffects() const;
        std::vector<long>                        activeEffects() const;
        QString                                  effectNameForId( long id ) const;
        bool                                     effectConfigurable( long id ) const;
        long                                     createEffect( const QString& name );
        void                                     removeEffect( long id );
        void                                     configureEffect( long id );
       
        bool                                     decoderConfigurable();
        bool                                     supportsXFade() const     { return true; }
         
    public slots:
        void                                     play( const KURL& );
        void                                     play();
        void                                     stop();
        void                                     pause();

        void                                     seek( long ms );
        void                                     setVolume( int percent );
        void                                     configureDecoder();                                                   

    private slots:
        void                                     connectPlayObject();
        void                                     connectTimeout();
    
    private:
        void                                     startXfade();
        void                                     timerEvent( QTimerEvent* );

        void                                     loadEffects();
        void                                     saveEffects();

        class ArtsConfigWidget : public QWidget
        {
            public:
                                                 ArtsConfigWidget( Arts::Object object );
                                                 ~ArtsConfigWidget();
            private:
                Arts::Widget                     m_gui;
                KArtsWidget                      *m_pArtsWidget;
        };

        struct EffectContainer
        {
            Arts::StereoEffect*                  effect;
            QGuardedPtr<ArtsConfigWidget>        widget;
        };

        /////////////////////////////////////////////////////////////////////////////////////
        // ATTRIBUTES
        /////////////////////////////////////////////////////////////////////////////////////
        static const int                         ARTS_TIMER = 100;   //ms
        static const int                         TIMEOUT    = 4000;  //ms FIXME make option?

        KArtsDispatcher*                         m_pArtsDispatcher;
        KDE::PlayObject*                         m_pPlayObject;
        KDE::PlayObject*                         m_pPlayObjectXfade;
        Arts::SoundServerV2                      m_server;
        Arts::StereoEffectStack                  m_globalEffectStack;
        Arts::StereoEffectStack                  m_effectStack;
        Arts::StereoVolumeControl                m_volumeControl;
        Arts::Synth_AMAN_PLAY                    m_amanPlay;
        Amarok::RawScope                         m_scope;
//        Arts::RawScope                           m_scope;
        Amarok::Synth_STEREO_XFADE               m_xfade;
//        Arts::Synth_STEREO_XFADE                 m_xfade;

        long                                     m_scopeId;
        int                                      m_scopeSize;
        long                                     m_volumeId;
        QMap<long, EffectContainer>              m_effectMap;

        bool                                     m_xfadeFadeout;
        float                                    m_xfadeValue;
        QString                                  m_xfadeCurrent;
        QGuardedPtr<ArtsConfigWidget>            m_pDecoderConfigWidget;
        QTimer*                                  m_pConnectTimer;
};

#endif

