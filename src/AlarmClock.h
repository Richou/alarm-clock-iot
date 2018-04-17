#include "BluetoothManager.h"

class AlarmClock {
    private:
        BluetoothManager * bluetoothManager;
    public:
        void initialize();
        void handle_alarm_clock();
};