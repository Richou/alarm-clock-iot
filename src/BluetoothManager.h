#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <SoftwareSerial.h>
#include "CommandParser.h"
#include "CommandObserver.h"

#define RX_PIN 11
#define TX_PIN 10

class BluetoothManager : public CommandObserver {
    void onReceivedDataFromSubject(String command) override;
    private:
        SoftwareSerial * softwareSerial;
        CommandParser * commandParser;
        String test = "test";
    public:
        void initialize();
        void handle_bluetooth();
};

#endif