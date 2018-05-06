#include <SoftwareSerial.h>

#define RX_PIN 11
#define TX_PIN 10

class BluetoothManager {
    private:
        SoftwareSerial * softwareSerial;
    public:
        void initialize();
        void handle_bluetooth();
};