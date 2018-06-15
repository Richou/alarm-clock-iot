#ifndef ALARM_PROCESS_H
#define ALARM_PROCESS_H

#include <Arduino.h>
#include "AlarmState.h"

class AlarmProcess {
    private:
        AlarmState state = AlarmState::OFF;
        uint32_t napDurationInMillis;
        long currentTimeAtNapSet;
    public:
        void handle_alarm();
        void setNapModeWithDurationInMillis(uint32_t durationInMillis);
};

#endif