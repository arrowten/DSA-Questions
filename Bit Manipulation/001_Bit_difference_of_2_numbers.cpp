#include <iostream>
#include <gtest/gtest.h>

int bit_difference_of_2_numbers(long long x, long long y) {
    long long N = (x ^ y); //XORing both the numbers
    int count = 0; //Stores the count of the different bits

    while(N) {
        N &= (N - 1);
        ++count;
    }

    return count;
}

TEST(Bit_difference_of_2_numbers, handles_various_cases) {
    EXPECT_EQ(bit_difference_of_2_numbers(10, 20), 4);
    EXPECT_EQ(bit_difference_of_2_numbers(20, 25), 3);
    EXPECT_EQ(bit_difference_of_2_numbers(3, 6), 2);
}