#ifndef COMMAND_OBSERVER_h
#define COMMAND_OBSERVER_h

#include <Arduino.h>

class CommandParser;

class CommandObserver {
    public:
        void attachSubject(CommandParser *parser);
        virtual void onReceivedDataFromSubject(String command) = 0;
};

#endif