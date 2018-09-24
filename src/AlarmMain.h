#ifndef ALARM_MAIN_H
#define ALARM_MAIN_H

#include <Arduino.h>
#include "AlarmClock.h"
#include "AlarmSetup.h"
#include "AlarmState.h"

class AlarmMain {
    private:
        AlarmClock alarmClock;
        AlarmSetup alarmSetup;
        AlarmState mainState = AlarmState::WORKING;
        long _buttonTimer = 0;
        uint32_t _longPressTime = 250;
        boolean _buttonActive = false;
        boolean _longPressActive = false;
        bool _longPressOffsetReached();
    public:
        void initialize();
        void handle();
};

#endif