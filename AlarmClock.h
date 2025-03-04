#pragma once

class AlarmClock {
public:
    AlarmClock() = default;  
    bool setTime(int hours, int minutes);
    int getHours() const;
    int getMinutes() const;
    bool ringsAt(int hours, int minutes) const;
private:
    int _hours = 0;
    int _minutes = 0;
};

