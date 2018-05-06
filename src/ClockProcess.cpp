#include "ClockProcess.h"
#include <Time.h>

int state = LOW;

void ClockProcess::displayHour() {
    Serial.print(hour());
    Serial.print(":");
    Serial.println(minute());
}

void ClockProcess::blinkSecond() {
    digitalWrite(2, state);
    if (state == LOW) state = HIGH;
    else state = LOW;  
}

void ClockProcess::initialize() {
    Serial.println("Initialize ClockProcess");
    pinMode(2, OUTPUT);
    timer = new Timer();
    timer->every(60000, ClockProcess::displayHour);
    timer->every(500, ClockProcess::blinkSecond);
}

void ClockProcess::process() {
    timer->update();
}