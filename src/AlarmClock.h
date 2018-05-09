#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include "BluetoothManager.h"
#include "ClockProcess.h"

class AlarmClock {
    private:
        BluetoothManager * bluetoothManager;
        ClockProcess * clockProcess;
    public:
        void initialize();
        void handle_alarm_clock();
};

#endif