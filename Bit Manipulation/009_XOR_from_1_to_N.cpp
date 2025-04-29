#include <iostream>
#include <gtest/gtest.h>

int XOR_from_1_to_N(unsigned long long N) {
    if(N == 1) return 1;
    else if(N % 4 == 0) return N;
    else if(N % 4 == 1) return 1;
    else if(N % 4 == 2) return N + 1;
    else return 0;
}

TEST(XOR_from_1_to_N, handles_various_cases) {
    EXPECT_EQ(XOR_from_1_to_N(1), 1);
    EXPECT_EQ(XOR_from_1_to_N(2), 3);
    EXPECT_EQ(XOR_from_1_to_N(3), 0);
    EXPECT_EQ(XOR_from_1_to_N(4), 4);
    EXPECT_EQ(XOR_from_1_to_N(5), 1);
    EXPECT_EQ(XOR_from_1_to_N(6), 7);
    EXPECT_EQ(XOR_from_1_to_N(7), 0);
    EXPECT_EQ(XOR_from_1_to_N(8), 8);
    EXPECT_EQ(XOR_from_1_to_N(9), 1);
    EXPECT_EQ(XOR_from_1_to_N(10), 11);
    EXPECT_EQ(XOR_from_1_to_N(11), 0);
    EXPECT_EQ(XOR_from_1_to_N(12), 12);
}