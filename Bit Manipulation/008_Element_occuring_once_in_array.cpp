#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int element_occurring_once_in_array(const std::vector<int>& nums) {
    if(nums.size() == 0) {
        return -1;
    }
    
    int result = nums[0];
    int size = nums.size();

    for(int i = 1; i < size; i++) {
        result ^= nums[i];
    }
    return result;
}

TEST(Element_occurring_once_in_array, handles_various_cases) {
    const std::vector<int> nums = {2, 3, 4, 5, 2, 5, 7, 3, 4};
    const std::vector<int> nums2 = {2, 8, 9, 3, 8, 9, 4, 2, 3};

    EXPECT_EQ(element_occurring_once_in_array(nums), 7);
    EXPECT_EQ(element_occurring_once_in_array(nums2), 4);
}