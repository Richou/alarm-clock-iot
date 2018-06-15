#include "AlarmProcess.h"

void AlarmProcess::setNapModeWithDurationInMillis(uint32_t durationInMillis) {
    Serial.print("Setting Nap Mode with duration : ");
    Serial.println(durationInMillis);
    state = AlarmState::NAP;
    napDurationInMillis = durationInMillis;
    currentTimeAtNapSet = millis();
}

void AlarmProcess::handle_alarm() {
    if (state == AlarmState::NAP && currentTimeAtNapSet + napDurationInMillis == millis()) {
        state = AlarmState::OFF;
        Serial.println("BEEP BEEP BEEP ! Nap OVER !");
    }
}