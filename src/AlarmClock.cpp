#include <Arduino.h>
#include "AlarmClock.h"

void AlarmClock::initialize() {
    bluetoothManager = new BluetoothManager();
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