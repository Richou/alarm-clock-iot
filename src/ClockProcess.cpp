#include "ClockProcess.h"
#include <Time.h>

void ClockProcess::initialize() {
    pinMode(LED_SECOND_PINOUT, OUTPUT);
    sevenSegmentsDisplay.initialize();
    rtc.begin();
}

void ClockProcess::_sendClockToDisplay() {
    DateTime current = rtc.now();
    int hourminutes = current.hour() * 100 + current.minute();
    secondBlink = !secondBlink;
    sevenSegmentsDisplay.displayClock(hourminutes, secondBlink);
}

void ClockProcess::process() {
    long currentMillis = millis();

    if (currentMillis - _previousTimeForBlink >= _computeSecondBlinkInterval()) {
        _previousTimeForBlink = currentMillis;
        _sendClockToDisplay();
    }
}

long ClockProcess::_computeSecondBlinkInterval() {
    if (this->_is_time_set || rtc.now().year() >= 2018) {
        this->_is_time_set = true;
        return _blinkInterval;
    }
    return this->_datetimeNotSetBlink;
}

void ClockProcess::setDateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    rtc.adjust(DateTime(year, month, day, hours, minutes, seconds));
}