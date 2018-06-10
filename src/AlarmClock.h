#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include "BluetoothManager.h"
#include "ClockProcess.h"
#include "AlarmObserver.h"

class AlarmClock : public AlarmObserver {
    private:
        BluetoothManager * bluetoothManager;
        ClockProcess * clockProcess;
    public:
        void initialize();
        void handle_alarm_clock();
        void onSetDatetime(int year, int month, int day, int hours, int minutes) override;
};

#endif