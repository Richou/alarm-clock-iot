#include "ClockProcess.h"
#include <Time.h>

void ClockProcess::_blinkLedSecond() {
    digitalWrite(LED_SECOND_PINOUT, _state);
    _state = (_state == LOW) ? HIGH : LOW;
}

void ClockProcess::_printDigit(int digit) {
    if (digit < 10) Serial.print("0");
    Serial.print(digit);
}

void ClockProcess::initialize() {
    Serial.println("Initialize ClockProcess");
    pinMode(LED_SECOND_PINOUT, OUTPUT);
    sevenSegmentsDisplay.initialize();
}

void ClockProcess::_sendClockToDisplay() {
    int hourminutes = hour() * 100 + minute();
    sevenSegmentsDisplay.displayToSevenSegs(hourminutes);
}

void ClockProcess::process() {
    if (_debugFlag == 0) {
        Serial.println("Starting Clock");
        _debugFlag = 1;
    }
    long currentMillis = millis();

    if (currentMillis - _previousTimeForBlink >= _computeSecondBlinkInterval()) {
        _previousTimeForBlink = currentMillis;
        _blinkLedSecond();
    }

    _sendClockToDisplay();
}

long ClockProcess::_computeSecondBlinkInterval() {
    timeStatus_t currentTimeStatus = timeStatus();
    if (currentTimeStatus == timeStatus_t::timeSet) return _blinkInterval;
    return _datetimeNotSetBlink;
}

void ClockProcess::setDateTime(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes) {
    setTime(hours, minutes, 0, day, month, year);
}