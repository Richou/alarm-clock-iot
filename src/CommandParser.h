#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <Arduino.h>

class CommandParser {
    public:
        void parseCommand(String command);
};

#endif