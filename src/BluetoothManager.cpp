#include <Arduino.h>
#include "BluetoothManager.h"
#include "AlarmObserver.h"
#include "AlarmDisplay.h"

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

void BluetoothManager::onReceivedSetDatetimeCommand(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) {
    if (mObserver != nullptr) {
        mObserver->onSetDatetime(year, month, day, hours, minutes, seconds);
    }
}

void BluetoothManager::onReceivedSetNapCommand(uint32_t durationInMillis) {
    if (mObserver != nullptr) {
        mObserver->onSetNapDuration(durationInMillis);
    }
}

void BluetoothManager::onReceivedSetSnoozeCommand(uint32_t durationInMillis) {
    if (mObserver != nullptr) {
        mObserver->onSetSnoozeDuration(durationInMillis);
    }
}

void BluetoothManager::onReceivedSetDisplayCommand(String display) {
    if (mObserver != nullptr) {
        AlarmDisplay commandDisplay = AlarmDisplay::CLOCK;
        if (display == "temperature") commandDisplay = AlarmDisplay::TEMPERATURE;
        mObserver->onSetDisplayMode(commandDisplay);
    }
}

void BluetoothManager::registerObserver(AlarmObserver* obs) {
    mObserver = obs;
}

void BluetoothManager::unregisterObserver() {
    mObserver = nullptr;
}