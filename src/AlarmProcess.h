#ifndef ALARM_PROCESS_H
#define ALARM_PROCESS_H

#include <Arduino.h>
#include <Wire.h>
#include "VL53L0X.h"
#include "AlarmState.h"
#include "Structs.h"

#define ALARM_PINOUT 6
#define ALARM_STOP_INPUT 7
#define HIGH_SPEED

class AlarmProcess {
    private:
        AlarmState state = AlarmState::OFF;
        uint32_t napDurationInMillis;
        uint32_t snoozeDurationInMillis = 5000;
        long currentTimeAtNapSet;
        bool _napTimeIsOver();
        bool _snoozeTimeIsOver();
        void _setup_laser_sensor();
        VL53L0X sensor;
    public:
        void initialize();
        void handle_alarm();
        void setNapModeWithDurationInMillis(uint32_t durationInMillis);
        void setSnoozeDurationInMillis(uint32_t snoozeDurationInMillis);
        void setAlarmClock(AlarmData alarm);
};

#endif