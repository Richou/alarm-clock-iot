#include <Arduino.h>
#include "AlarmClock.h"

void AlarmClock::initialize() {
    bluetoothManager = new BluetoothManager();
    attachSubject(bluetoothManager);
    bluetoothManager->initialize();
    clockProcess.initialize();
    alarmProcess.initialize();
    temperatureProcess.initialize();
}

void AlarmClock::handle_alarm_clock() {
    bluetoothManager->handle_bluetooth();
    alarmProcess.handle_alarm();
    (currentDisplay == AlarmDisplay::CLOCK) ? clockProcess.process() : temperatureProcess.process();
}

void AlarmClock::onSetDatetime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    clockProcess.setDateTime(year, month, day, hours, minutes, seconds);
}

void AlarmClock::onSetColor(uint8_t red, uint8_t green, uint8_t blue) {
    ledDisplay.setColor(red, green, blue);
}

void AlarmClock::onSetBrightness(uint8_t brightness) {
    ledDisplay.setBrightness(brightness);
}

void AlarmClock::onSetNapDuration(uint32_t durationInMillis) {
    alarmProcess.setNapModeWithDurationInMillis(durationInMillis);
}

void AlarmClock::onSetSnoozeDuration(uint32_t durationInMillis) {
    alarmProcess.setSnoozeDurationInMillis(durationInMillis);
}

void AlarmClock::onSetAlarm(AlarmData alarm) {
    alarmProcess.setAlarmClock(alarm);
}

void AlarmClock::onSetDisplayMode(AlarmDisplay newDisplay) {
    this->currentDisplay = newDisplay;
}