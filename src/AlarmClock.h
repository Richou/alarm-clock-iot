#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include "BluetoothManager.h"
#include "ClockProcess.h"
#include "AlarmObserver.h"
#include "AlarmProcess.h"

class AlarmClock : public AlarmObserver {
    private:
        BluetoothManager * bluetoothManager;
        ClockProcess clockProcess;
        AlarmProcess alarmProcess;
    public:
        void initialize();
        void handle_alarm_clock();
        void onSetDatetime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) override;
        void onSetNapDuration(uint32_t duration) override;
};

#endif