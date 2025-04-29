#include <iostream>
#include <gtest/gtest.h>

bool number_is_strict_power_of_2_check(unsigned long long N) {
    return (N & (N - 1)) == 0;
}

TEST(Number_is_strict_power_of_2_check, handles_various_cases) {
    EXPECT_TRUE(number_is_strict_power_of_2_check(4));
    EXPECT_TRUE(number_is_strict_power_of_2_check(256));
    EXPECT_TRUE(number_is_strict_power_of_2_check(1024));
    EXPECT_TRUE(number_is_strict_power_of_2_check(8192));
    EXPECT_FALSE(number_is_strict_power_of_2_check(7));
    EXPECT_FALSE(number_is_strict_power_of_2_check(-2));
}