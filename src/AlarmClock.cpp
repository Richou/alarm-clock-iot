#include <Arduino.h>
#include "AlarmClock.h"

void AlarmClock::initialize() {
    bluetoothManager = new BluetoothManager();
    attachSubject(bluetoothManager);
    bluetoothManager->initialize();
    clockProcess = new ClockProcess();
    clockProcess->initialize();
    Serial.begin(9600);
    Serial.println("Begining AlarmClock");
}

void AlarmClock::handle_alarm_clock() {
    bluetoothManager->handle_bluetooth();
    clockProcess->process();
}

void AlarmClock::onSetDatetime(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes) {
    Serial.print("Setting time -> ");
    Serial.print(hours);
    Serial.print(":");
    Serial.println(minutes);
    clockProcess->setDateTime(year, month, day, hours, minutes);
}