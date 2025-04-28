#include <iostream>
#include <gtest/gtest.h>

int set_bit_count_in_number(long long N) {
    int count = 0;

    while(N) {
        N &= (N - 1);
        ++count;
    }
    
    return count;
}

TEST(Set_bit_count_in_number, handles_various_cases) {
    EXPECT_EQ(set_bit_count_in_number(10), 2);
    EXPECT_EQ(set_bit_count_in_number(20), 2);
    EXPECT_EQ(set_bit_count_in_number(7), 3);
}