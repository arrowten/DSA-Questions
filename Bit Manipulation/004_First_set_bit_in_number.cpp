#include <iostream>
#include <gtest/gtest.h>

int first_set_bit_in_number(unsigned long long N) {
    int count = 0;
    
    while(N > 0) {
        N >>= 1;
        count++;
    }
    
    return count;
}

TEST(First_set_bit_in_number, handles_various_cases) {
    EXPECT_EQ(first_set_bit_in_number(4), 3);
    EXPECT_EQ(first_set_bit_in_number(6), 3);
    EXPECT_EQ(first_set_bit_in_number(14), 4);
    EXPECT_EQ(first_set_bit_in_number(256), 9);
}