#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <gtest/gtest.h>

std::pair<int, int> subarray_sum_of_size_K(const std::vector<int>& nums, int K) {
    if(nums.size() == 0 || K > nums.size() || K <= 0) {
        return {INT_MIN, INT_MAX};
    }

    int i = 1, j = K;   // Window size
    int size = nums.size();
    int maximum = INT_MIN, minimum = INT_MAX;
    int window_sum = 0;

    // Calculate the sum of the first window
    for(int l = 0; l < K; l++) {
        window_sum += nums[l];
    }

    maximum = window_sum;
    minimum = window_sum;

    // Calculate the sum of the remaining windows
    while(j < size) {
        window_sum += nums[j] - nums[i - 1];
        maximum = std::max(window_sum, maximum);
        minimum = std::min(window_sum, minimum);
        i++; j++;
    }

    return {maximum, minimum};
}

TEST(Subarray_sum_of_size_K, handles_various_cases) {    
    const std::vector<int> nums = {100, 200, 300, 400};
    const std::vector<int> nums2 = {1, 2, 3, -2, 5};

    EXPECT_EQ(subarray_sum_of_size_K(nums, 2), (std::pair<int, int>{700, 300}));
    EXPECT_EQ(subarray_sum_of_size_K(nums, 3), (std::pair<int, int>{900, 600}));
    EXPECT_EQ(subarray_sum_of_size_K(nums2, 2), (std::pair<int, int>{5, 1}));
    EXPECT_EQ(subarray_sum_of_size_K(nums2, 3), (std::pair<int, int>{6, 3}));
}