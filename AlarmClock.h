#pragma once

class AlarmClock {
public:
    AlarmClock() = default;  
    void setTime(int hours, int minutes);
    int getHours() const;
    int getMinutes() const;
private:
    int _hours = 0;
    int _minutes = 0;
};

