#ifndef COMMAND_OBSERVER_h
#define COMMAND_OBSERVER_h

#include <Arduino.h>

class CommandParser;

class CommandObserver {
    public:
        void attachSubject(CommandParser *parser);
        virtual void onReceivedSetDatetimeCommand(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) = 0;
        virtual void onReceivedSetColorCommand(uint8_t red, uint8_t green, uint8_t blue) = 0;
        virtual void onReceivedSetNapCommand(uint32_t durationInMillis) = 0;
        virtual void onReceivedSetSnoozeCommand(uint32_t durationInMillis) = 0;
        virtual void onReceivedSetDisplayCommand(String display) = 0;
        virtual void onReceivedSetAlarmCommand(String daysOfWeek, String hour) = 0;
        virtual void onReceivedSetBrightnessCommand(uint8_t brightness) = 0;
};

#endif