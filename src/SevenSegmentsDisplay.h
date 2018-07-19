#ifndef SEVEN_SEGMENTS_DISPLAY_H
#define SEVEN_SEGMENTS_DISPLAY_H
#include <TM1637Display.h>

#define CLOCK_PIN 4
#define DATA_PIN 3

class SevenSegmentsDisplay {
    private:
        TM1637Display *display;
        uint8_t* _convertIntToSegments(int temperature);
    public:
        void initialize();
        void displayClock(int hourminute, bool showColon);
        void displayTemperature(int temperature);
};

#endif