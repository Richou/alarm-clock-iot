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

void AlarmClock::onSetDatetime(int year, int month, int day, int hours, int minutes) {
    Serial.print("Setting Date with year");
    Serial.println(year);
}