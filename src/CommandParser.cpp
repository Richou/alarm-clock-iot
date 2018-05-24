#include "CommandParser.h"
#include "CommandObserver.h"

void CommandParser::parseCommand(String command) {
    Serial.print("Recevied Command ");
    Serial.println(command);
    if (command.startsWith(set_clock_cmd)) {
        Serial.print("setting clock to -> ");
        String new_clock = extractValueFromCommand(command, set_clock_cmd);
    }
    if (command.startsWith(set_nap_cmd)) {
        Serial.print("Setting nap of -> ");
        String nap_time = extractValueFromCommand(command, set_nap_cmd);
        uint32_t factor = 1;
        if (nap_time.endsWith("m")) factor = 60;
        if (nap_time.endsWith("h")) factor = 60 * 60;
        nap_time.remove(nap_time.length() - 1);
        uint32_t nap_time_in_millis = nap_time.toInt() * factor * 1000;
        Serial.println(nap_time_in_millis);
        mObserver->onReceivedSetNapCommand(nap_time_in_millis);
    }
    if (command.startsWith(set_alarm_cmd)) {
        Serial.print("Setting Alarm for -> ");
        String new_alarm = extractValueFromCommand(command, set_alarm_cmd);
        Serial.println(new_alarm);
    }
    _notifyObserver(command);
}

String CommandParser::extractValueFromCommand(String received, String command) {
    return received.substring(command.length());
}

void CommandParser::registerObserver(CommandObserver* obs) {
    mObserver = obs;
}

void CommandParser::unregisterObserver() {
    mObserver = nullptr;
}

void CommandParser::_notifyObserver(String command) {
    if (mObserver != nullptr) {
        mObserver->onReceivedDataFromSubject(command); 
    }
}