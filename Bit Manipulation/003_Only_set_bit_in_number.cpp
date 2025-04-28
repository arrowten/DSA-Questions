#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

int only_set_bit_in_number(unsigned long long N) {
	if((N & (N - 1)) != 0) {
		return -1;
	}
	else {
		return (std::log2(N));
	}
}

TEST(Only_set_bit_in_number, handles_various_cases) {
	unsigned long long N = 8;
	unsigned long long N2 = 256;
	unsigned long long N3 = 2048;
	unsigned long long N4 = 135;
	unsigned long long N5 = 2147483648;

	EXPECT_EQ(only_set_bit_in_number(N), 3);
	EXPECT_EQ(only_set_bit_in_number(N2), 8);
	EXPECT_EQ(only_set_bit_in_number(N3), 11);
	EXPECT_EQ(only_set_bit_in_number(N4), -1);
	EXPECT_EQ(only_set_bit_in_number(N5), 31);
}