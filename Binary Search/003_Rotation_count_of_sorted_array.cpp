#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int rotation_count_of_sorted_array(const std::vector<int>& nums) {
    if(nums.size() == 0) {
        return -1;
    }
    
    int left = 0, right = nums.size() - 1;

    while(left <= right) {
        // If first number is smaller than the last number, its sorted already
        if(nums[left] <= nums[right]) {
            return left;
        }
        
        int middle = left + (right - left) / 2;
        int next = (middle + 1) % nums.size();
        int previous = (middle - 1 + nums.size()) % nums.size();

        // If middle number is smaller than its neighbors, then that position is the number of times the array is rotated
        if(nums[middle] <= nums[previous] && nums[middle] <= nums[next]) {
            return middle;
        }

        if(nums[middle] >= nums[left]) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return 0;
}

TEST(Rotation_count_of_sorted_array, handles_various_cases) {
    const std::vector<int> nums = {15, 18, 2, 5, 6, 8, 11, 12};
    const std::vector<int> nums2 = {7, 9, 11, 12, 5};
    const std::vector<int> nums3 = {7, 9, 11, 12, 15};

    EXPECT_EQ(rotation_count_of_sorted_array(nums), 2);
    EXPECT_EQ(rotation_count_of_sorted_array(nums2), 4);
    EXPECT_EQ(rotation_count_of_sorted_array(nums3), 0);
}