#include "AlarmClock.h"

bool AlarmClock::setTime(int hours, int minutes) {
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        return false;
    }
    _hours = hours;
    _minutes = minutes;
    return true;
}

int AlarmClock::getHours() const {
    return _hours;
}

int AlarmClock::getMinutes() const {
    return _minutes;
}

bool AlarmClock::ringsAt(int hours, int minutes) const {
    return _hours == hours && _minutes == minutes;
}

std::string AlarmClock::ring() const {
    return "Playing melody!";
}