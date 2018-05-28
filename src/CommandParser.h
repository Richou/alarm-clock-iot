#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>

class CommandObserver;

class CommandParser {
    private:
        // Set DateTime pattern : set-datetime|yyyy-MM-ddThh:mmZ
        String set_clock_cmd = "set-datetime|";
        // Set Alarm pattern : set-alarm|m,t,w,t,f,s,s|hh:mm
        // Set Alarm pattern : set-alarm|1,1,1,1,1,0,0|hh:mm
        String set_alarm_cmd = "set-alarm|";
        // Set Nap pattern : set-nap|20m or set-nap|1h
        String set_nap_cmd = "set-nap|";

        String extractValueFromCommand(String received, String command);
        CommandObserver* mObserver;
        void _notifyObserver(String command);
    public:
        void parseCommand(String command);
        void registerObserver(CommandObserver*); 
        void unregisterObserver();
};

#endif