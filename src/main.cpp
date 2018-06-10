#include <Arduino.h>
#include "AlarmClock.h"

AlarmClock alarmClock;

void setup() {
    alarmClock.initialize();
}

void loop() {
    alarmClock.handle_alarm_clock();
}