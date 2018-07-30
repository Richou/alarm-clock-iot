#ifndef STRUCTS_H
#define STRUCTS_H

#include <Arduino.h>

struct AlarmData {
    bool* daysMustAwake;
    uint8_t hourToAwake;
    uint8_t minuteToAwake;
};

#endif