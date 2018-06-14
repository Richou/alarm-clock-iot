#ifndef SEVEN_SEGMENTS_DISPLAY_H
#define SEVEN_SEGMENTS_DISPLAY_H

#define LATCH_PIN 2
#define CLOCK_PIN 3
#define DATA_PIN 4

class SevenSegmentsDisplay {
    private:
        int multiplexing_offset = 1;
        void _send_data(short data);
    public:
        void initialize();
        void displayToSevenSegs(int hourminute);
};

#endif