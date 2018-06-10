#include "AlarmObserver.h"
#include "BluetoothManager.h"

void AlarmObserver::attachSubject(BluetoothManager *subject) {
    subject->registerObserver(this);
}