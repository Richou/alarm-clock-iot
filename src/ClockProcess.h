#ifndef CLOCK_PROCESS_H
#define CLOCL_PROCESS_H

#include <Arduino.h>
#include "AlarmState.h"
#include "SevenSegmentsDisplay.h"

#define LED_SECOND_PINOUT 5

class ClockProcess {
    private:
        AlarmState state = AlarmState::INIT;
        SevenSegmentsDisplay sevenSegmentsDisplay;
        int _state = HIGH;
        int _debugFlag = 0;
        long _previousTimeForBlink = 0;
        long _blinkInterval = 500;
        long _datetimeNotSetBlink = 100;
        void _blinkLedSecond();
        void _printDigit(int digit);
        void _sendClockToDisplay();
        long _computeSecondBlinkInterval();
    public:
        void initialize();
        void process();
        void setDateTime(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes);
};

#endif