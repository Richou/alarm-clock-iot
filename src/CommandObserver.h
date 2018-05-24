#ifndef COMMAND_OBSERVER_h
#define COMMAND_OBSERVER_h

#include <Arduino.h>

class CommandParser;

class CommandObserver {
    public:
        void attachSubject(CommandParser *parser);
        virtual void onReceivedDataFromSubject(String command) = 0;
        virtual void onReceivedSetDatetimeCommand(int year, int month, int day, int hours, int minutes) = 0;
        virtual void onReceivedSetNapCommand(uint32_t durationInMillis) = 0;
};

#endif