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

TEST(AlarmClockTest, RejectsInvalidTime) {
    AlarmClock alarm;
    EXPECT_FALSE(alarm.setTime(-1, 30));
    EXPECT_FALSE(alarm.setTime(24, 0));   
    EXPECT_FALSE(alarm.setTime(10, -5));  
    EXPECT_FALSE(alarm.setTime(10, 60));  
}