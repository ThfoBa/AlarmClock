#include "AlarmClock.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

int main() {
    AlarmClock alarm;
    int hours, minutes;
    std::cout << "¬ведите врем€ будильника (часы и минуты): ";
    std::cin >> hours >> minutes;
    alarm.setTime(hours, minutes);
    std::cout << "Ѕудильник установлен на " << alarm.getHours() << ":" << alarm.getMinutes() << std::endl;
    while (true) {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* localTime = std::localtime(&now);
        int currentHours = localTime->tm_hour;
        int currentMinutes = localTime->tm_min;
        if (alarm.ringsAt(currentHours, currentMinutes)) {
            std::cout << alarm.ring(currentHours, currentMinutes) << std::endl;
            break; 
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}