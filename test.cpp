#include <gtest/gtest.h>
#include "AlarmClock.h"
  
TEST(AlarmClockTest, CanBeCreated) {
    AlarmClock alarm;
}

TEST(AlarmClockTest, CanSetTime) {
    AlarmClock alarm;
    alarm.setTime(7, 30);
    EXPECT_EQ(alarm.getHours(), 7);
    EXPECT_EQ(alarm.getMinutes(), 30);
}