#include "TemperatureProcess.h"

void TemperatureProcess::initialize() {
    pinMode(TEMPERATURE_SENSOR_PININ, INPUT);
}

void TemperatureProcess::process() {
    int sensorValue = analogRead(TEMPERATURE_SENSOR_PININ);

    float voltage = (sensorValue/1024.0) * 5.0;

    float temperature = (voltage - 0.5) * 100;

    long currentMillis = millis();

    if (currentMillis - _previous_refresh_interval_ms >= _display_refresh_interval_ms) {
        _previous_refresh_interval_ms = currentMillis;
        Serial.print("Temperature : ");
        Serial.print(temperature);
        Serial.println("°C");
    }
}