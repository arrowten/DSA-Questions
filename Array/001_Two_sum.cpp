#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::pair<int, int> two_sum(const std::vector<int>& nums, int target) {
    if(nums.size() == 0 || target == 0) {
        return {-1, -1};
    }
    
    std::unordered_map<int, int> mp;
    std::pair<int, int> result;
    int size = nums.size();

    for(int i = 0; i < size; i++) {
        // The number we need to find to complete the pair
        int complement = target - nums[i];
        
        // If it exists, return the indices: first is from the map, second is current index
        if(mp.find(complement) != mp.end()) {
            return {mp[complement], i};
        }
        
        // Otherwise, add the current number and its index to the map
        mp[nums[i]] = i;
    }
    
    return result;
}

TEST(Two_sum, handles_various_cases) {
    const std::vector<int> nums = {2, 7, 11, 15};
    const std::vector<int> nums2 = {3, 2, 4};
    const std::vector<int> nums3 = {3, 3};

    EXPECT_EQ(two_sum(nums, 9), (std::pair<int, int>{0, 1}));
    EXPECT_EQ(two_sum(nums2, 6), (std::pair<int, int>{1, 2}));
    EXPECT_EQ(two_sum(nums3, 6), (std::pair<int, int>{0, 1}));
}