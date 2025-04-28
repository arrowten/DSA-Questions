#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int count_of_element_in_sorted_array(const std::vector<int>& nums, int target) {
    if(nums.size() == 0) {
        return -1;
    }
    
    int left = 0, right = nums.size() - 1, result = 0;

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

            result = last - first + 1;

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

TEST(Count_of_element_in_sorted_array, handles_various_cases) {
    const std::vector<int> nums = {5, 7, 7, 8, 8, 10};

    EXPECT_EQ(count_of_element_in_sorted_array(nums, 7), 2);
    EXPECT_EQ(count_of_element_in_sorted_array(nums, 8), 2);
    EXPECT_EQ(count_of_element_in_sorted_array(nums, 9), 0);
}