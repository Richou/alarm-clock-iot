#ifndef CLOCK_PROCESS_H
#define CLOCL_PROCESS_H

#include <Arduino.h>

class ClockProcess {
    private:
        int _state = LOW;
        long _previousTimeForBlink = 0;
        long _previousTimeForClock = 0;
        long _blinkInterval = 500;
        long _clockInverval = 60000;
        void _blinkSecond();
        void _displayClock();
        void _printDigit(int digit);
    public:
        void initialize();
        void process();
};

#endif