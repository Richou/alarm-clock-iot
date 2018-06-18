#ifndef ALARM_PROCESS_H
#define ALARM_PROCESS_H

#include <Arduino.h>
#include <Wire.h>
#include "VL53L0X.h"
#include "AlarmState.h"

#define ALARM_PINOUT 6
#define HIGH_SPEED

class AlarmProcess {
    private:
        AlarmState state = AlarmState::OFF;
        uint32_t napDurationInMillis;
        long currentTimeAtNapSet;
        bool _napTimeIsOver();
        void _setup_laser_sensor();
        VL53L0X sensor;
    public:
        void initialize();
        void handle_alarm();
        void setNapModeWithDurationInMillis(uint32_t durationInMillis);
};

#endif