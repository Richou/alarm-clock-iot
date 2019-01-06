#ifndef ALARM_SETUP_H
#define ALARM_SETUP_H

#include <Arduino.h>

// Class to Init the Alarm Clock IoT (bluetooth pairing, with security password)
class AlarmSetup {
    private:
        long _generated_password;
    public:
        void initialize();
        void handle_alarm_setup();
};

#endif