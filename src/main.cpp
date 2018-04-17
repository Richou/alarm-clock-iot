#include <Arduino.h>
#include "AlarmClock.h"

AlarmClock* alarmClock;

void setup() {
    alarmClock = new AlarmClock();
    alarmClock->initialize();
}

void loop() {
    alarmClock->handle_alarm_clock();
}