#ifndef TEMPERATURE_PROCESS_H
#define TEMPERATURE_PROCESS_H

#include <Arduino.h>

#define TEMPERATURE_SENSOR_PININ A0

class TemperatureProcess {
    private:
        long _display_refresh_interval_ms = 1000;
        long _previous_refresh_interval_ms = 0;
    public:
        void initialize();
        void process();
};

#endif