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

void BluetoothManager::onReceivedSetAlarmCommand(String daysOfWeek, String hour) {
    if (mObserver != nullptr) {
        AlarmData alarm;
        char hour_minute_p[hour.length()];
        hour.toCharArray(hour_minute_p, hour.length() + 1);
        uint16_t hour_ac, minute_ac;
        sscanf(hour_minute_p, TIME_PATTERN, &hour_ac, &minute_ac);
        alarm.hourToAwake = hour_ac;
        alarm.minuteToAwake = minute_ac;

        char days_of_week_p[daysOfWeek.length()];
        daysOfWeek.toCharArray(days_of_week_p, daysOfWeek.length() + 1);
        int sunday, monday, tuesday, wednesday, thursday, friday, saturday;
        sscanf(days_of_week_p, DAYS_OF_WEEK_PATTERN, &sunday, &monday, &tuesday, &wednesday, &thursday, &friday, &saturday);
        bool dayOfWeekToRing[7];
        dayOfWeekToRing[0] = this->_fromIntToBool(sunday);
        dayOfWeekToRing[1] = this->_fromIntToBool(monday);
        dayOfWeekToRing[2] = this->_fromIntToBool(tuesday);
        dayOfWeekToRing[3] = this->_fromIntToBool(wednesday);
        dayOfWeekToRing[4] = this->_fromIntToBool(thursday);
        dayOfWeekToRing[5] = this->_fromIntToBool(friday);
        dayOfWeekToRing[6] = this->_fromIntToBool(saturday);
        alarm.daysMustAwake = dayOfWeekToRing;
        mObserver->onSetAlarm(alarm);
    }
}

bool BluetoothManager::_fromIntToBool(int toConvert) {
    return toConvert == 1;
}

void BluetoothManager::registerObserver(AlarmObserver* obs) {
    mObserver = obs;
}

void BluetoothManager::unregisterObserver() {
    mObserver = nullptr;
}