#include "TemperatureProcess.h"

void TemperatureProcess::initialize() {
    pinMode(TEMPERATURE_SENSOR_PININ, INPUT);
    sevenSegmentsDisplay.initialize();
}

void TemperatureProcess::process() {
    long currentMillis = millis();

    if (currentMillis - _previous_refresh_interval_ms >= _display_refresh_interval_ms) {
        _previous_refresh_interval_ms = currentMillis;
        int sensorValue = analogRead(TEMPERATURE_SENSOR_PININ);

        float voltage = (sensorValue/1024.0) * 5.0;

        _temperature = (voltage - 0.5) * 100;
        sevenSegmentsDisplay.displayTemperature((int)(_temperature * 10));
    }
}