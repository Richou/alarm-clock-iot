#include "AlarmProcess.h"

void AlarmProcess::setNapModeWithDurationInMillis(uint32_t durationInMillis) {
    Serial.println(durationInMillis);
    state = AlarmState::NAP;
    napDurationInMillis = durationInMillis;
    currentTimeAtNapSet = millis();
}

void AlarmProcess::setSnoozeDurationInMillis(uint32_t snoozeDurationInMillis) {
    this->snoozeDurationInMillis = snoozeDurationInMillis; 
}

void AlarmProcess::initialize() {
    pinMode(ALARM_PINOUT, OUTPUT);
    pinMode(ALARM_STOP_INPUT, INPUT);
    Wire.begin();
    sensor.init();
    sensor.setTimeout(0);
    sensor.setMeasurementTimingBudget(20000);
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
    if (state == AlarmState::SNOOZE && _snoozeTimeIsOver()) {
        state = AlarmState::BEEPING;
        digitalWrite(ALARM_PINOUT, HIGH);
        _setup_laser_sensor();
    }
    if (state == AlarmState::BEEPING && sensor.readRangeContinuousMillimeters() < 150) {
        state = AlarmState::SNOOZE;
        currentTimeAtNapSet = millis();
        digitalWrite(ALARM_PINOUT, LOW);
    }
    if (digitalRead(ALARM_STOP_INPUT) == HIGH) {
        state = AlarmState::OFF;
        digitalWrite(ALARM_PINOUT, LOW);
    }
}

bool AlarmProcess::_napTimeIsOver() {
    return millis() > currentTimeAtNapSet + napDurationInMillis;
}

bool AlarmProcess::_snoozeTimeIsOver() {
    return millis() > currentTimeAtNapSet + this->snoozeDurationInMillis;
}

void AlarmProcess::_setup_laser_sensor() {
    sensor.startContinuous();
}