#include "AlarmProcess.h"

void AlarmProcess::setNapModeWithDurationInMillis(uint32_t durationInMillis) {
    Serial.print("Setting Nap Mode with duration : ");
    Serial.println(durationInMillis);
    state = AlarmState::NAP;
    napDurationInMillis = durationInMillis;
    currentTimeAtNapSet = millis();
}

void AlarmProcess::initialize() {
    pinMode(ALARM_PINOUT, OUTPUT);
}

void AlarmProcess::handle_alarm() {
    if (state == AlarmState::NAP && _napTimeIsOver()) {
        state = AlarmState::BEEPING;
        digitalWrite(ALARM_PINOUT, HIGH);
        _setup_laser_sensor();
    }
    if (state != AlarmState::NAP && state == AlarmState::ALARM) {
        state = AlarmState::BEEPING;
    }
    if (state == AlarmState::BEEPING && sensor.readRangeContinuousMillimeters() < 150) {
        state = AlarmState::OFF;
        sensor.stopContinuous();
        Wire.end();
        digitalWrite(ALARM_PINOUT, LOW);
    }
}

bool AlarmProcess::_napTimeIsOver() {
    return millis() > currentTimeAtNapSet + napDurationInMillis;
}

void AlarmProcess::_setup_laser_sensor() {
    Wire.begin();
    sensor.init();
    sensor.setTimeout(0);
    sensor.setMeasurementTimingBudget(20000);
    sensor.startContinuous();
}