#include "AlarmSetup.h"

void AlarmSetup::initialize() {
    _generated_password = random(1000, 10000);
    Serial.print("Generated Password : ");
    Serial.println(_generated_password);
}

void AlarmSetup::handle_alarm_setup() {
    
}