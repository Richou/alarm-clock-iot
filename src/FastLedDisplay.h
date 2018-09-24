#ifndef FAST_LED_DISPLAY_H
#define FAST_LED_DISPLAY_H

#include <FastLED.h>

#define AC_NUM_LEDS 30
#define AC_DATA_PINOUT 6 

class FastLedDisplay {
    private:
        CRGB _LEDs[AC_NUM_LEDS];
        CRGB _currentColor = CRGB::BlueViolet;
        const CRGB _colorOFF = CRGB::Black;
        void _displaySegments(int startindex, int number);
        void _displayDots(bool showColon);
    public:
        void initialize();
        void displayClock(int hourminute, bool showColon);
        void displayTemperature(int temperature);
        void setBrightness(uint8_t brightness);
        void setColor(uint8_t reg, uint8_t green, uint8_t blue);
};

#endif