#include "AlarmClock.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    AlarmClock alarm;
    int hours, minutes;
    std::cout << "Введите время будильника (часы и минуты): ";
    std::cin >> hours >> minutes;
    alarm.setTime(hours, minutes);
    std::cout << "Будильник установлен на " << alarm.getHours() << ":" << alarm.getMinutes() << std::endl;
    while (true) {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* localTime = std::localtime(&now);
        int currentHours = localTime->tm_hour;
        int currentMinutes = localTime->tm_min;
        if (alarm.ringsAt(currentHours, currentMinutes)) {
            std::cout << alarm.ring(currentHours, currentMinutes) << std::endl;
            std::cout << "Нажмите любую клавишу, чтобы выключить будильник.\n";
            _getch();
            alarm.stopAlarm();
            break; 
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}