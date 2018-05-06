#include "BluetoothManager.h"
#include "ClockProcess.h"

class AlarmClock {
    private:
        BluetoothManager * bluetoothManager;
        ClockProcess * clockProcess;
    public:
        void initialize();
        void handle_alarm_clock();
};