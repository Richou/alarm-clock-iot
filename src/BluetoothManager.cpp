#include <Arduino.h>
#include "BluetoothManager.h"

void BluetoothManager::initialize() {
    softwareSerial = new SoftwareSerial(RX_PIN, TX_PIN);
    softwareSerial->begin(9600);
    Serial.begin(9600);
}

void BluetoothManager::handle_bluetooth() {
    if (softwareSerial->available()) {
        String command = softwareSerial->readString();
        Serial.println(command);
    }
    if (Serial.available()) {
        softwareSerial->println(Serial.readString());
    }
}