#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <SoftwareSerial.h>
#include "CommandParser.h"

#define RX_PIN 11
#define TX_PIN 10

class BluetoothManager {
    private:
        SoftwareSerial * softwareSerial;
        CommandParser * commandParser;
    public:
        void initialize();
        void handle_bluetooth();
};

#endif