#include "QvkThreadAlsa.h"

#include <QDebug>
#include <QAudioDeviceInfo>

QvkThreadAlsa::QvkThreadAlsa()
{
    timer = new QTimer( this );
    timer->setInterval( 5000 );
    connect( timer, SIGNAL( timeout() ), this, SLOT( slot_trigger_Thread() ) );
}


QvkThreadAlsa::~QvkThreadAlsa()
{
}


void QvkThreadAlsa::run()
{
    qDebug() << "void QvkThreadAlsa::run()";
    emit signal_countAudioDevices( QAudioDeviceInfo::availableDevices( QAudio::AudioInput ).count() );
}


void QvkThreadAlsa::slot_trigger_Thread()
{
    start();
}


void QvkThreadAlsa::slot_set_first_start( bool value )
{
    firstStart = value;
}


void QvkThreadAlsa::slot_start_stop_thread_timer( bool value )
{
  if ( firstStart == true )
  {
      firstStart = false;
      start();
      timer->start();
  }
  else
  {
    if ( value == true )
        timer->start();
    else
        timer->stop();
  }
}