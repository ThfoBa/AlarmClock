#pragma once
#include <string>
#include <Windows.h>
#include <mmsystem.h> 
using namespace std;
#pragma comment(lib, "winmm.lib")

class AlarmClock {
public:
    AlarmClock() = default;  
    bool setTime(int hours, int minutes);
    int getHours() const;
    int getMinutes() const;
    bool ringsAt(int hours, int minutes) const;
    std::string ring(int hours, int minutes) const;  
private:
    int _hours = 0;
    int _minutes = 0;
};

