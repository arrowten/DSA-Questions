#include <iostream>
#include <gtest/gtest.h>

void swap_2_numbers(long long& x, long long& y) {
    x ^= y;
    y ^= x;
    x ^= y;
}

TEST(Swap_2_numbers, handles_various_cases) {
    long long a = 13, b = 9;
    long long a2 = 15, b2 = 8;

    swap_2_numbers(a, b);
    swap_2_numbers(a2, b2);

    EXPECT_EQ(a, 9);
    EXPECT_EQ(b, 13);
    EXPECT_EQ(a2, 8);
    EXPECT_EQ(b2, 15);
}