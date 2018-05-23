#include <Arduino.h>
#include "BluetoothManager.h"

void BluetoothManager::initialize() {
    softwareSerial = new SoftwareSerial(TX_PIN, RX_PIN);
    softwareSerial->begin(9600);
    Serial.begin(9600);

    commandParser = new CommandParser();
    attachSubject(commandParser);
}

void BluetoothManager::handle_bluetooth() {
    if (softwareSerial->available()) {
        String command = softwareSerial->readString();
        commandParser->parseCommand(command);
    }
}

void BluetoothManager::onReceivedDataFromSubject(const String command) {
    Serial.print("Value is "); Serial.println(command);
}