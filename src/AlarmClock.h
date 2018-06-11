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
        void onSetDatetime(uint8_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes) override;
};

#endif