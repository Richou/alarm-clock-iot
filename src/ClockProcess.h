#include <Arduino.h>
#include <Timer.h>

class ClockProcess {
    private:
        Timer* timer;
    public:
        void initialize();
        void process();
        static void displayHour();
        static void blinkSecond();
};