#ifndef ALARM_OBSERVER_H
#define ALARM_OBSERVER_H

class BluetoothManager;

class AlarmObserver {
    public:
        void attachSubject(BluetoothManager *subject);
        virtual void onSetDatetime(int year, int month, int day, int hours, int minutes) = 0;
};

#endif