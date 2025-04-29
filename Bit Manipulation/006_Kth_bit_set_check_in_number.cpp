#include <iostream>
#include <gtest/gtest.h>

bool Kth_bit_set_check_in_number(unsigned int N, int k) {
    if((N >> (k - 1)) & 1) {
        return true;
    }

    return false;
}

TEST(Kth_bit_set_check_in_number, handles_various_cases) {
    EXPECT_TRUE(Kth_bit_set_check_in_number(5, 3));
    EXPECT_TRUE(Kth_bit_set_check_in_number(5, 3));
    EXPECT_TRUE(Kth_bit_set_check_in_number(4, 3));
    EXPECT_TRUE(Kth_bit_set_check_in_number(20, 5));
    EXPECT_FALSE(Kth_bit_set_check_in_number(4, 2));
}