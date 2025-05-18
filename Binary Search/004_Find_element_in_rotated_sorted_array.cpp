#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int find_element_in_rotated_sorted_array(const std::vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return -1;
    }
    
    int left = 0, right = nums.size() - 1;

    while(left <= right) {
        int middle = left + (right - left) / 2;

        // If number found in the middle, then return that position
        if(nums[middle] == target) {
            return middle;
        }

        if(nums[left] <= nums[middle]) { // Left hald is sorted
            if(nums[left] <= target && target < nums[middle]) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }
        else { // Right half is sorted
            if(nums[middle] < target && target <= nums[right]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
    }

    return -1;
}

TEST(Find_element_in_rotated_sorted_array, handles_various_cases) {
    const std::vector<int> nums = {15, 18, 2, 5, 6, 8, 11, 12};
    const std::vector<int> nums2 = {7, 9, 11, 12, 5};

    EXPECT_EQ(find_element_in_rotated_sorted_array(nums, 6), 4);
    EXPECT_EQ(find_element_in_rotated_sorted_array(nums2, 11), 2);
}