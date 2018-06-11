#include "CommandParser.h"
#include "CommandObserver.h"

void CommandParser::parseCommand(String command) {
    Serial.print("Recevied Command ");
    Serial.println(command);
    if (command.startsWith(set_clock_cmd)) {
        String new_clock = extractValueFromCommand(command, set_clock_cmd);
        char new_clock_p[new_clock.length()];
        new_clock.toCharArray(new_clock_p, new_clock.length());
        int year_ac, month_ac, day_ac, minutes_ac, hours_ac;
        sscanf(new_clock_p, DATE_TIME_PATTERN, &year_ac, &month_ac, &day_ac, &hours_ac, &minutes_ac);
        mObserver->onReceivedSetDatetimeCommand(year_ac, month_ac, day_ac, hours_ac, minutes_ac);
    }
    if (command.startsWith(set_nap_cmd)) {
        String nap_time = extractValueFromCommand(command, set_nap_cmd);
        uint32_t factor = 1;
        if (nap_time.endsWith("m")) factor = 60;
        if (nap_time.endsWith("h")) factor = 60 * 60;
        nap_time.remove(nap_time.length() - 1);
        uint32_t nap_time_in_millis = nap_time.toInt() * factor * 1000;
        mObserver->onReceivedSetNapCommand(nap_time_in_millis);
    }
    if (command.startsWith(set_alarm_cmd)) {
        Serial.print("Setting Alarm for -> ");
        String new_alarm = extractValueFromCommand(command, set_alarm_cmd);
        Serial.println(new_alarm);
    }
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