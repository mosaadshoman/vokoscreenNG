#include "QvkAudioWindows.h"

#include <QAudioDeviceInfo>
#include <QDebug>

QvkAudioWindows::QvkAudioWindows( Ui_MainWindow *ui_mainwindow )
{
    ui = ui_mainwindow;
}


QvkAudioWindows::~QvkAudioWindows()
{
}


void QvkAudioWindows::slot_getWindowsDevices()
{
    foreach (const QAudioDeviceInfo &deviceInfo, QAudioDeviceInfo::availableDevices( QAudio::AudioInput ) )
    {
        QCheckBox *checkboxAudioDevice = new QCheckBox();
        checkboxAudioDevice->setText( deviceInfo.deviceName() );
        checkboxAudioDevice->setAccessibleName( deviceInfo.deviceName() );
        checkboxAudioDevice->setObjectName( "checkboxAudioDevice" + deviceInfo.deviceName() );
        ui->verticalLayoutAudioDevices->addWidget( checkboxAudioDevice );
        checkboxAudioDevice->setAutoExclusive( true );
    }
    QSpacerItem *verticalSpacerAudioDevices = new QSpacerItem( 20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding );
    ui->verticalLayoutAudioDevices->addSpacerItem( verticalSpacerAudioDevices );
}
