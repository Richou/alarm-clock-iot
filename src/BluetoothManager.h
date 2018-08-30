#ifndef BLUETOOTH_MANAGER_H
#define BLUETOOTH_MANAGER_H

#include <SoftwareSerial.h>
#include "CommandParser.h"
#include "CommandObserver.h"
#include "Structs.h"

#define RX_PIN 9
#define TX_PIN 8

class AlarmObserver;

class BluetoothManager : public CommandObserver {
    private:
        static constexpr const char* TIME_PATTERN = "%d:%d";
        static constexpr const char* DAYS_OF_WEEK_PATTERN = "%i,%i,%i,%i,%i,%i,%i";
        SoftwareSerial * softwareSerial;
        CommandParser * commandParser;
        String test = "test";
        AlarmObserver* mObserver;
        bool _fromIntToBool(int toConvert);
    public:
        ~BluetoothManager();
        void initialize();
        void handle_bluetooth();
        void onReceivedSetDatetimeCommand(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, uint8_t seconds) override;
        void onReceivedSetNapCommand(uint32_t durationInMillis) override;
        void onReceivedSetSnoozeCommand(uint32_t durationInMillis) override;
        void onReceivedSetDisplayCommand(String display) override;
        void onReceivedSetAlarmCommand(String daysOfWeek, String hour) override;
        void registerObserver(AlarmObserver*);
        void unregisterObserver();
};

#endif