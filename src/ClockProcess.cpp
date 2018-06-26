#include "ClockProcess.h"
#include <Time.h>

void ClockProcess::_blinkLedSecond() {
    digitalWrite(LED_SECOND_PINOUT, _state);
    _state = (_state == LOW) ? HIGH : LOW;
    // uint8_t dayOfTheWeek = rtc.now().dayOfTheWeek();
}

void ClockProcess::_printDigit(int digit) {
    if (digit < 10) Serial.print("0");
    Serial.print(digit);
}

void ClockProcess::initialize() {
    pinMode(LED_SECOND_PINOUT, OUTPUT);
    sevenSegmentsDisplay.initialize();
    rtc.begin();
}

void ClockProcess::_sendClockToDisplay() {
    DateTime current = rtc.now();
    int hourminutes = current.hour() * 100 + current.minute();
    sevenSegmentsDisplay.displayToSevenSegs(hourminutes);
}

void ClockProcess::process() {
    long currentMillis = millis();

    if (currentMillis - _previousTimeForBlink >= _computeSecondBlinkInterval()) {
        _previousTimeForBlink = currentMillis;
        _blinkLedSecond();
    }

    _sendClockToDisplay();
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