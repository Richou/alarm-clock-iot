#include "ClockProcess.h"
#include <Time.h>

void ClockProcess::_blinkSecond() {
    digitalWrite(2, _state);
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
    pinMode(2, OUTPUT);
}

void ClockProcess::process() {
    long currentMillis = millis();
    if (currentMillis - _previousTimeForBlink >= _blinkInterval) {
        _previousTimeForBlink = currentMillis;
        _blinkSecond();
    }

    if (currentMillis - _previousTimeForClock >= _clockInverval) {
        _previousTimeForClock = currentMillis;
        _displayClock();
    }
}