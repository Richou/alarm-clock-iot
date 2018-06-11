#ifndef ALARM_OBSERVER_H
#define ALARM_OBSERVER_H
#include <Arduino.h>

class BluetoothManager;

class AlarmObserver {
    public:
        void attachSubject(BluetoothManager *subject);
        virtual void onSetDatetime(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes) = 0;
};

#endif