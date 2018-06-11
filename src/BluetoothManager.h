#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <SoftwareSerial.h>
#include "CommandParser.h"
#include "CommandObserver.h"

#define RX_PIN 11
#define TX_PIN 10

class AlarmObserver;

class BluetoothManager : public CommandObserver {
    private:
        SoftwareSerial * softwareSerial;
        CommandParser * commandParser;
        String test = "test";
        AlarmObserver* mObserver;
    public:
        ~BluetoothManager();
        void initialize();
        void handle_bluetooth();
        void onReceivedSetDatetimeCommand(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes) override;
        void onReceivedSetNapCommand(uint32_t durationInMillis) override;

        void registerObserver(AlarmObserver*); 
        void unregisterObserver();
};

#endif