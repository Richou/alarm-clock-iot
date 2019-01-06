#include "AlarmMain.h"
#include "Structs.h"

void AlarmMain::initialize() {
    pinMode(ALARM_STOP_INPUT, INPUT);
    alarmClock.initialize();
}

void AlarmMain::handle() {
    if (mainState == AlarmState::WORKING) {
		alarmClock.handle_alarm_clock();
	}
    if (mainState == AlarmState::SETUP) {
		alarmSetup.handle_alarm_setup();
	}
}

bool AlarmMain::_longPressOffsetReached() {
    return millis() - _buttonTimer >= _longPressTime;
}