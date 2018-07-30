#include "AlarmProcess.h"

void AlarmProcess::setNapModeWithDurationInMillis(uint32_t durationInMillis) {
    state = AlarmState::PROGRAM;
    _isNapSet = true;
    napDurationInMillis = durationInMillis;
    currentTimeAtNapSet = millis();
}

void AlarmProcess::setSnoozeDurationInMillis(uint32_t snoozeDurationInMillis) {
    Serial.println(snoozeDurationInMillis);
    this->snoozeDurationInMillis = snoozeDurationInMillis; 
}

void AlarmProcess::setAlarmClock(AlarmData alarm) {
    alarmData = alarm;
    state = AlarmState::PROGRAM;
    _isAlarmSet = true;
}

void AlarmProcess::initialize() {
    pinMode(ALARM_PINOUT, OUTPUT);
    pinMode(ALARM_STOP_INPUT, INPUT);
    rtc.begin();
    Wire.begin();
    sensor.init();
    sensor.setTimeout(0);
    sensor.setMeasurementTimingBudget(20000);
}

void AlarmProcess::handle_alarm() {
    if (state == AlarmState::PROGRAM && _isNapSet && _napTimeIsOver()) {
        state = AlarmState::BEEPING;
        digitalWrite(ALARM_PINOUT, HIGH);
        _setup_laser_sensor();
    }
    if (state == AlarmState::PROGRAM && _isAlarmSet && _alarmTimeHasArrived()) {
        state = AlarmState::BEEPING;
        digitalWrite(ALARM_PINOUT, HIGH);
        _setup_laser_sensor();
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
        state = AlarmState::PROGRAM;
        _isNapSet = false;
        digitalWrite(ALARM_PINOUT, LOW);
    }
}

bool AlarmProcess::_alarmTimeHasArrived() {
    long currentMillis = millis();
    if (currentMillis - previousAlarmCheck >= alarmCheckOffset) {
        previousAlarmCheck = currentMillis;
        return alarmData.daysMustAwake[rtc.now().dayOfTheWeek()] && alarmData.hourToAwake == rtc.now().hour() && alarmData.minuteToAwake == rtc.now().minute() && rtc.now().second() == 0;
    }
    return false;
}

bool AlarmProcess::_napTimeIsOver() {
    return millis() - currentTimeAtNapSet >= napDurationInMillis;
}

bool AlarmProcess::_snoozeTimeIsOver() {
    return millis() - currentTimeAtNapSet >= snoozeDurationInMillis;
}

void AlarmProcess::_setup_laser_sensor() {
    sensor.startContinuous();
}