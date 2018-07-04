#include <Arduino.h>
#include "SevenSegmentsDisplay.h"

void SevenSegmentsDisplay::initialize() {
    pinMode(LATCH_PIN, OUTPUT);
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    digitalWrite(LATCH_PIN, LOW);
}

void SevenSegmentsDisplay::displayToSevenSegs(int data) {
    short ones, tens, hundreds, thousands;

    thousands = int(data/1000);
    thousands = (thousands<<4)+1;

    hundreds = int(data/100);
    hundreds = hundreds-(int(hundreds/10)*10);
    hundreds = (hundreds<<4)+2;

    tens = int(data/10);
    tens = tens-(int(tens/10)*10);
    tens = (tens<<4)+4;

    ones = data-(int(data/10)*10);
    ones = (ones<<4)+8;

    _send_data(thousands);
    _send_data(hundreds);
    _send_data(tens);
    _send_data(ones);

    digitalWrite(2, LOW);
}

void SevenSegmentsDisplay::_send_data(short data) {
    digitalWrite(2, LOW);
    shiftOut(4, 3,MSBFIRST, data);
    digitalWrite(2, HIGH);
    delay(5);
}