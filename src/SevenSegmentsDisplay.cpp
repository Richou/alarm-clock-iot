#include <Arduino.h>
#include "SevenSegmentsDisplay.h"

void SevenSegmentsDisplay::initialize() {
    display = new TM1637Display(CLOCK_PIN, DATA_PIN);
    display->setBrightness(0x0f);
}

void SevenSegmentsDisplay::displayClock(int minutehour, bool showColon) {
    uint8_t colon = 0b00000000;
    if (showColon) colon = 0b01000000;
    display->showNumberDecEx(minutehour, colon, true, 4, 0);
}

void SevenSegmentsDisplay::displayTemperature(int temperature) {
    display->setSegments(this->_convertIntToSegments(temperature));
}

uint8_t* SevenSegmentsDisplay::_convertIntToSegments(int temperature) {
    int hundreds = temperature/100;
    int tens = (temperature%100)/10;
    uint8_t* data = new uint8_t[4];

    data[0] = display->encodeDigit(hundreds);
    data[1] = display->encodeDigit(tens);
    data[2] = SEG_A | SEG_F | SEG_G | SEG_B;
    data[3] = display->encodeDigit(12);
    return data;
}