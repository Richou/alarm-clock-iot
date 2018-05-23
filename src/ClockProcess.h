#ifndef CLOCK_PROCESS_H
#define CLOCL_PROCESS_H

#include <Arduino.h>
#include "AlarmState.h"

#define LED_SECOND_PINOUT 2

class ClockProcess {
    private:
        AlarmState state = AlarmState::INIT;
        int _state = HIGH;
        int _debugFlag = 0;
        long _previousTimeForBlink = 0;
        long _previousTimeForClock = 0;
        long _blinkInterval = 500;
        long _datetimeNotSetBlink = 100;
        long _clockInverval = 60000;
        void _blinkLedSecond();
        void _displayClock();
        void _printDigit(int digit);
    public:
        void initialize();
        void process();
        void setDateTime();
};

#endif