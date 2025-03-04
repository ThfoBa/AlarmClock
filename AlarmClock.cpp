#include "AlarmClock.h"

bool AlarmClock::setTime(int hours, int minutes) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        return false;
    }
    _hours = hours;
    _minutes = minutes;
    return true;
}

int AlarmClock::getHours() {
    return _hours;
}

int AlarmClock::getMinutes() {
    return _minutes;
}

bool AlarmClock::ringsAt(int hours, int minutes) {
    return _hours == hours && _minutes == minutes;
}

void AlarmClock::playSound() {
    if (isRinging) return;

    isRinging = true;
    alarmThread = std::thread([this]() {
        mciSendString(TEXT("open \"D:\\lab3\\x64\\Debug\\alarm.mp3\" alias alarm"), NULL, 0, NULL);

        while (isRinging) {
            mciSendString(TEXT("play alarm repeat"), NULL, 0, NULL);
            std::this_thread::sleep_for(std::chrono::seconds(1)); 
        }

        mciSendString(TEXT("close alarm"), NULL, 0, NULL);
        });
}

void AlarmClock::stopAlarm() {
    isRinging = false;
    if (alarmThread.joinable()) {
        alarmThread.join();
    }
}

std::string AlarmClock::ring(int hours, int minutes) {
    if (_hours == hours && _minutes == minutes) {
        playSound();
        return "Playing melody!";
    }
    return "";
}