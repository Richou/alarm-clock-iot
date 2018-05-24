#include "ClockProcess.h"
#include <Time.h>

void ClockProcess::_blinkLedSecond() {
    digitalWrite(LED_SECOND_PINOUT, _state);
    _state = (_state == LOW) ? HIGH : LOW;
}

void ClockProcess::_displayClock() {
    _printDigit(hour());
    Serial.print(":");
    _printDigit(minute());
    Serial.println();
}

void ClockProcess::_printDigit(int digit) {
    if (digit < 10) Serial.print("0");
    Serial.print(digit);
}

void ClockProcess::initialize() {
    Serial.println("Initialize ClockProcess");
    pinMode(LED_SECOND_PINOUT, OUTPUT);
}

void ClockProcess::process() {
    if (_debugFlag == 0) {
        Serial.println("Starting Clock");
        _debugFlag = 1;
    }
    long currentMillis = millis();
    if (currentMillis - _previousTimeForBlink >= _blinkInterval) {
        _previousTimeForBlink = currentMillis;
        _blinkLedSecond();
    }

    if (currentMillis - _previousTimeForClock >= _clockInverval) {
        _previousTimeForClock = currentMillis;
        _displayClock();
    }
}

void ClockProcess::setDateTime(int year, int month, int day, int hours, int minutes) {
    setTime(hours, minutes, 0, day, month, year);
}