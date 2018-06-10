#include <Arduino.h>
#include "BluetoothManager.h"
#include "AlarmObserver.h"

BluetoothManager::~BluetoothManager() {
    commandParser->unregisterObserver();
    delete commandParser;
}

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

void BluetoothManager::onReceivedSetDatetimeCommand(int year, int month, int day, int hours, int minutes) {
    if (mObserver != nullptr) {
        mObserver->onSetDatetime(year, month, day, hours, minutes);
    }
}

void BluetoothManager::onReceivedSetNapCommand(uint32_t durationInMillis) {
    Serial.print("Setting napTime for ");
    Serial.print(durationInMillis);
    Serial.println(" ms");
}

void BluetoothManager::registerObserver(AlarmObserver* obs) {
    mObserver = obs;
}

void BluetoothManager::unregisterObserver() {
    mObserver = nullptr;
}