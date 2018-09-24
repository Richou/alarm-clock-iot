#ifndef SEVEN_SEGMENTS_DISPLAY_H
#define SEVEN_SEGMENTS_DISPLAY_H
#include <TM1637Display.h>

#define AC_CLOCK_PIN 4
#define DATA_PIN_FOR_SEVEN_SEGMENTS_DISPLAY 3

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