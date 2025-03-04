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
    PlaySound(TEXT("alarm.mp3"), NULL, SND_FILENAME | SND_ASYNC);
}

std::string AlarmClock::ring(int hours, int minutes) {
    if (_hours == hours && _minutes == minutes) {
        playSound();
        return "Playing melody!";
    }
    return "";
}