#include "CommandParser.h"
#include "CommandObserver.h"

void CommandParser::parseCommand(String command) {
    Serial.print("Recevied Command ");
    Serial.println(command);
    if (command.startsWith(set_clock_cmd)) {
        String new_clock = extractValueFromCommand(command, set_clock_cmd);
        char new_clock_p[new_clock.length()];
        new_clock.toCharArray(new_clock_p, new_clock.length());
        uint16_t year_ac;
        int month_ac, day_ac, minutes_ac, hours_ac, seconds_ac;
        sscanf(new_clock_p, DATE_TIME_PATTERN, &year_ac, &month_ac, &day_ac, &hours_ac, &minutes_ac, &seconds_ac);
        mObserver->onReceivedSetDatetimeCommand(year_ac, month_ac, day_ac, hours_ac, minutes_ac, seconds_ac);
    }
    if (command.startsWith(set_nap_cmd)) {
        String nap_time = extractValueFromCommand(command, set_nap_cmd);
        mObserver->onReceivedSetNapCommand(this->extractDurationInMillis(nap_time));
    }
    if (command.startsWith(set_snooze_cmd)) {
        String snooze_time = extractValueFromCommand(command, set_snooze_cmd);
        mObserver->onReceivedSetSnoozeCommand(this->extractDurationInMillis(snooze_time));
    }
    if (command.startsWith(set_alarm_cmd)) {
        String new_alarm = extractValueFromCommand(command, set_alarm_cmd);
        mObserver->onReceivedSetAlarmCommand(new_alarm.substring(0, new_alarm.indexOf("|")), new_alarm.substring(new_alarm.indexOf("|") + 1));
    }
    if (command.startsWith(set_display_cmd)) {
        String new_display = extractValueFromCommand(command, set_display_cmd);
        mObserver->onReceivedSetDisplayCommand(new_display);
    }
}

uint32_t CommandParser::extractDurationInMillis(String inValue) {
    uint32_t factor = 1;
    if (inValue.endsWith("m")) factor = 60;
    if (inValue.endsWith("h")) factor = 60 * 60;
    inValue.remove(inValue.length() - 1);
    return inValue.toInt() * factor * 1000;
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