#ifndef CLOCK_PROCESS_H
#define CLOCL_PROCESS_H

#include <Arduino.h>
#include "AlarmState.h"
#include "SevenSegmentsDisplay.h"
#include "RTClib.h"

#define LED_SECOND_PINOUT 5

class ClockProcess {
    private:
        AlarmState state = AlarmState::INIT;
        SevenSegmentsDisplay sevenSegmentsDisplay;
        RTC_DS1307 rtc;
        bool secondBlink = false;
        bool _is_time_set = false;
        long _previousTimeForBlink = 0;
        long _blinkInterval = 500;
        long _datetimeNotSetBlink = 100;
        void _printDigit(int digit);
        void _sendClockToDisplay();
        long _computeSecondBlinkInterval();
    public:
        void initialize();
        void process();
        void setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds);
};

#endif