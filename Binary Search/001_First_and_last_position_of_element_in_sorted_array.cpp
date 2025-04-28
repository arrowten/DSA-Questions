#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::pair<int, int> first_and_last_positions_of_element_in_sorted_array(const std::vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return {-1, -1};
    }

    int left = 0, right = nums.size() - 1;
    std::pair<int, int> result{-1, -1};

    while(left <= right) {
        int middle = left + (right - left) / 2;

        // If number is found in the middle
        if(nums[middle] == target) {
            int first = middle, last = middle;

            // Go till the first occurrence
            while(first > 0 && nums[first - 1] == target) {
                first--;
            }
            
            // Go till the last occurrence
            while((last < nums.size() - 1) && nums[last + 1] == target) {
                last++;
            }

            result = {first, last};

            return result;
        }
        else if(nums[middle] < target) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return result;
}

TEST(First_and_last_positions_of_element_in_sorted_array, handles_various_cases) {
    const std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    const std::vector<int> nums2 = {};

    EXPECT_EQ(first_and_last_positions_of_element_in_sorted_array(nums, 7), (std::pair<int, int>{1, 2}));
    EXPECT_EQ(first_and_last_positions_of_element_in_sorted_array(nums, 8), (std::pair<int, int>{3, 4}));
    EXPECT_EQ(first_and_last_positions_of_element_in_sorted_array(nums, 6), (std::pair<int, int>{-1, -1}));
    EXPECT_EQ(first_and_last_positions_of_element_in_sorted_array(nums2, 3), (std::pair<int, int>{-1, -1}));
}