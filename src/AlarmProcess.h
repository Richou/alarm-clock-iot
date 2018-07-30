#ifndef ALARM_PROCESS_H
#define ALARM_PROCESS_H

#include <Arduino.h>
#include <Wire.h>
#include "VL53L0X.h"
#include "AlarmState.h"
#include "Structs.h"
#include "RTClib.h"

#define ALARM_PINOUT 6
#define ALARM_STOP_INPUT 7
#define HIGH_SPEED

class AlarmProcess {
    private:
        RTC_DS1307 rtc;
        AlarmState state = AlarmState::OFF;
        uint32_t napDurationInMillis;
        uint32_t snoozeDurationInMillis = 600000;
        uint32_t alarmCheckOffset = 1000;
        long currentTimeAtNapSet;
        unsigned long previousAlarmCheck = 0;
        bool _napTimeIsOver();
        bool _isNapSet = false;
        bool _alarmTimeHasArrived();
        bool _isAlarmSet = false;
        bool _snoozeTimeIsOver();
        void _setup_laser_sensor();
        VL53L0X sensor;
        AlarmData alarmData;
    public:
        void initialize();
        void handle_alarm();
        void setNapModeWithDurationInMillis(uint32_t durationInMillis);
        void setSnoozeDurationInMillis(uint32_t snoozeDurationInMillis);
        void setAlarmClock(AlarmData alarm);
};

#endif