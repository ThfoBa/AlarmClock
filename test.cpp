#include <gtest/gtest.h>
#include "AlarmClock.h"
  
TEST(AlarmClockTest, CanBeCreated) {
    AlarmClock alarm;
}

TEST(AlarmClockTest, CanSetTime) {
    AlarmClock alarm;
    alarm.setTime(7, 30);
}