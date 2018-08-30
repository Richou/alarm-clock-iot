#include "FastLedDisplay.h"

void FastLedDisplay::initialize() {
    FastLED.delay(1000);
    FastLED.addLeds<WS2812B, DATA_PINOUT, RGB>(LEDs, NUM_LEDS);
}

void FastLedDisplay::displayClock(int hourminute, bool showColon) {
    int ones, tens, hundreds, thousands;

    thousands = int(hourminute/1000);

    hundreds = int(hourminute/100);
    hundreds = hundreds-(int(hundreds/10)*10);

    tens = int(hourminute/10);
    tens = tens-(int(tens/10)*10);

    ones = hourminute-(int(hourminute/10)*10);
    
    _displaySegments(0, ones);    
    _displaySegments(7, tens);
    _displaySegments(16, hundreds);    
    _displaySegments(23, thousands);  
    _displayDots(showColon);
    FastLED.show();
}

void FastLedDisplay::displayTemperature(int temperature) {
    int hundreds = temperature/100;
    int tens = (temperature%100)/10;
    
    _displaySegments(0, 11);    
    _displaySegments(7, 10);
    _displaySegments(16, tens);    
    _displaySegments(23, hundreds);
    _displayDots(false);
    FastLED.show();
}

void FastLedDisplay::_displaySegments(int startindex, int number) {

  byte numbers[] = {
    0b00111111, // 0    
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111, // 9   
    0b01100011, // º              10
    0b00111001, // C(elcius)      11
    0b01011100, // º lower        12
    0b00000000, // Empty          13
    0b01110001, // F(ahrenheit)   14
  };

  for (int i = 0; i < 7; i++) {
    LEDs[i + startindex] = ((numbers[number] & 1 << i) == 1 << i) ? CRGB::White : colorOFF;
  } 
}

void FastLedDisplay::_displayDots(bool showColon) {
    LEDs[14] = (showColon) ? CRGB::White : colorOFF;
    LEDs[15] = (showColon) ? CRGB::White : colorOFF;
}
