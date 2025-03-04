#include "AlarmClock.h"

void AlarmClock::setTime(int hours, int minutes) {
    _hours = hours;
    _minutes = minutes;
}

int AlarmClock::getHours() const {
    return _hours;
}

int AlarmClock::getMinutes() const {
    return _minutes;
}