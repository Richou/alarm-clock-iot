#include "AlarmMain.h"
#include "Structs.h"

void AlarmMain::initialize() {
    pinMode(ALARM_STOP_INPUT, INPUT);
    alarmClock.initialize();
    alarmSetup.initialize();
}

void AlarmMain::handle() {
	if (digitalRead(ALARM_STOP_INPUT) == HIGH) {
		if (_buttonActive == false) {
			_buttonActive = true;
			_buttonTimer = millis();
		}
		if ((_longPressOffsetReached()) && (_longPressActive == false)) {
			_longPressActive = true;
		}
	} else {
		if (_buttonActive == true) {
			if (_longPressActive == true) {
				_longPressActive = false;
			} else {
				
			}
			_buttonActive = false;
		}
	}

    if (mainState == AlarmState::WORKING) alarmClock.handle_alarm_clock();
    if (mainState == AlarmState::SETUP) alarmSetup.handle_alarm_setup();
}

bool AlarmMain::_longPressOffsetReached() {
    return millis() - _buttonTimer >= _longPressTime;
}