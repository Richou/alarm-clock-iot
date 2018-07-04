#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>

class CommandObserver;

class CommandParser {
    private:
        static constexpr const char* DATE_TIME_PATTERN = "%d-%d-%dT%d:%d:%dZ";
        // Set DateTime pattern : set-datetime|yyyy-MM-ddThh:mm:ssZ
        String set_clock_cmd = "set-datetime|";
        // Set Alarm pattern : set-alarm|s,m,t,w,t,f,s|hh:mm
        // Set Alarm pattern : set-alarm|0,1,1,1,1,1,0|hh:mm
        String set_alarm_cmd = "set-alarm|";
        // Set Nap pattern : set-nap|20m or set-nap|1h
        String set_nap_cmd = "set-nap|";
        // Set Snooze pattern : set-snooze|10m
        String set_snooze_cmd = "set-snooze|";
        // Set Display pattern : set-display|clock or temperature
        String set_display_cmd = "set-display|";
        uint32_t extractDurationInMillis(String inValue);
        String extractValueFromCommand(String received, String command);
        CommandObserver* mObserver;
    public:
        void parseCommand(String command);
        void registerObserver(CommandObserver*); 
        void unregisterObserver();
};

#endif