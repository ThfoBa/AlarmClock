#pragma once
#include <string>
#include <Windows.h>
#include <mmsystem.h> 
#include <thread>
#include <atomic>
#pragma comment(lib, "winmm.lib")

class AlarmClock {
public:
    AlarmClock() = default;
    bool setTime(int hours, int minutes);
    int getHours();
    int getMinutes();
    bool ringsAt(int hours, int minutes);
    void playSound();
    void stopAlarm();
    std::string ring(int hours, int minutes);
    std::atomic<bool> isRinging{ false };
private:
    int _hours = 0;
    int _minutes = 0;
    std::thread alarmThread;
};

