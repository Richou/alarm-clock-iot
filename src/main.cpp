#include <Arduino.h>
#include "AlarmMain.h"

AlarmMain alarmMain;

void setup() {
    alarmMain.initialize();
}

void loop() {
    alarmMain.handle();
}