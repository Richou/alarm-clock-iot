#ifndef ALARM_OBSERVER_H
#define ALARM_OBSERVER_H
#include <Arduino.h>
#include "AlarmDisplay.h"
#include "Structs.h"

class BluetoothManager;

class AlarmObserver {
    public:
        void attachSubject(BluetoothManager *subject);
        virtual void onSetDatetime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) = 0;
        virtual void onSetColor(uint8_t red, uint8_t green, uint8_t blue) = 0;
        virtual void onSetNapDuration(uint32_t durationInMillis) = 0;
        virtual void onSetSnoozeDuration(uint32_t durationInMillis) = 0;
        virtual void onSetDisplayMode(AlarmDisplay newDisplay) = 0;
        virtual void onSetBrightness(uint8_t brightness) = 0;
        virtual void onSetAlarm(AlarmData data) = 0;
};

#endif