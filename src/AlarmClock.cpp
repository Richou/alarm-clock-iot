#include <Arduino.h>
#include "AlarmClock.h"

void AlarmClock::initialize() {
    bluetoothManager = new BluetoothManager();
    attachSubject(bluetoothManager);
    bluetoothManager->initialize();
    clockProcess.initialize();
    alarmProcess.initialize();
}

void AlarmClock::handle_alarm_clock() {
    bluetoothManager->handle_bluetooth();
    clockProcess.process();
    alarmProcess.handle_alarm();
}

void AlarmClock::onSetDatetime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    clockProcess.setDateTime(year, month, day, hours, minutes, seconds);
}

void AlarmClock::onSetNapDuration(uint32_t durationInMillis) {
    alarmProcess.setNapModeWithDurationInMillis(durationInMillis);
}

void AlarmClock::onSetSnoozeDuration(uint32_t durationInMillis) {
    alarmProcess.setSnoozeDurationInMillis(durationInMillis);
}