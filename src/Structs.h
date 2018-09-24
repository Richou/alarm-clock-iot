#ifndef STRUCTS_H
#define STRUCTS_H

#include <Arduino.h>

#ifndef ALARM_STOP_INPUT
#define ALARM_STOP_INPUT 7
#endif

struct AlarmData {
    bool* daysMustAwake;
    uint8_t hourToAwake;
    uint8_t minuteToAwake;
};

#endif