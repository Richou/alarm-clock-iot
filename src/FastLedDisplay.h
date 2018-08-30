#ifndef FAST_LED_DISPLAY_H
#define FAST_LED_DISPLAY_H

#include <FastLED.h>

#define NUM_LEDS 30
#define DATA_PINOUT 6 

class FastLedDisplay {
    private:
        CRGB LEDs[NUM_LEDS];
        const CRGB colorOFF = CRGB::Black;
        void _displaySegments(int startindex, int number);
        void _displayDots(bool showColon);
    public:
        void initialize();
        void displayClock(int hourminute, bool showColon);
        void displayTemperature(int temperature);
};

#endif