#include "combo_sounddevices.h"

SoundDevicesComboBox::SoundDevicesComboBox(QWidget *parent) : QComboBox(parent)
{
    insertItem(count(), "Benedini - TBS Mini", SD_BENEDINI_TBSMINI);
    // FOR FUTURE USE
    //insertItem(count(), "Beier - USM-RC-2", SD_BEIER_USMRC2);
    // etc...

    // If either the text or index has changed, emit our custom signal
    connect(this, SIGNAL(editTextChanged(QString)), this, SLOT(CurrentDeviceChangedSlot()));
    connect(this, SIGNAL(currentIndexChanged(QString)), this, SLOT(CurrentDeviceChangedSlot()));
}

void SoundDevicesComboBox::CurrentDeviceChangedSlot()
{
    // Send out a signal with the new value as int (not index, but the sound_devices enum converted to int)
    emit currentSoundDeviceChanged(this->currentData().toInt());
}


// This returns the current actual sound_device
sound_devices SoundDevicesComboBox::getCurrentSoundDevice(void)
{
    return static_cast<sound_devices>(this->currentData().toInt());
}

// We can programmatically set the combo box to a value by passing it directly the enum code
void SoundDevicesComboBox::setCurrentSoundDevice(int sd)
{
    this->setCurrentIndex(this->findData(sd));
}

// We can programmatically set the combo box to a value by passing it a sound_devices enum member name
void SoundDevicesComboBox::setCurrentSoundDevice(const sound_devices& sd)
{
    this->setCurrentIndex(this->findData(sd));

}