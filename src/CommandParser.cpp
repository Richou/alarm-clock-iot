#include "CommandParser.h"

void CommandParser::parseCommand(String command) {
    Serial.print("Recevied Command ");
    Serial.println(command);
    if (command.startsWith(set_clock_cmd)) {
        Serial.print("setting clock to -> ");
        String new_clock = command.substring(set_clock_cmd.length());
        Serial.println(new_clock);
    }
}