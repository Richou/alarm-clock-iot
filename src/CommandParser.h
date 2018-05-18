#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>

class CommandParser {
    private:
        String set_clock_cmd = "set-datetime";
    public:
        void parseCommand(String command);
};

#endif