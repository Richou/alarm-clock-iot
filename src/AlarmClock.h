#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include "BluetoothManager.h"
#include "ClockProcess.h"
#include "AlarmObserver.h"
#include "AlarmProcess.h"
#include "TemperatureProcess.h"
#include "AlarmDisplay.h"
#include "Structs.h"
#include "FastLedDisplay.h"

class AlarmClock : public AlarmObserver {
    private:
        BluetoothManager * bluetoothManager;
        ClockProcess clockProcess;
        AlarmProcess alarmProcess;
        TemperatureProcess temperatureProcess;
        FastLedDisplay ledDisplay;
        AlarmDisplay currentDisplay = AlarmDisplay::CLOCK;
    public:
        void initialize();
        void handle_alarm_clock();
        void onSetDatetime(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) override;
        void onSetColor(uint8_t red, uint8_t green, uint8_t blue) override;
        void onSetBrightness(uint8_t brightness) override;
        void onSetNapDuration(uint32_t duration) override;
        void onSetSnoozeDuration(uint32_t durationInMillis) override;
        void onSetDisplayMode(AlarmDisplay newDisplay) override;
        void onSetAlarm(AlarmData alarm) override;
};

#endif