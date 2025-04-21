#include <iostream>
#include <vector>
#include <queue>
#include <gtest/gtest.h>

std::vector<int> first_negative_in_size_K(const std::vector<int>& nums, int K) {
    if(nums.size() == 0 || K > nums.size() || K <= 0) {
        return {};
    }

    std::vector<int> result;
    std::queue<int> q;
    int size = nums.size();

    //Process the first window
    for(int i = 0; i < K; i++) {
        if(nums[i] < 0) {
            q.push(i);
        }
    }

    //Process the remaining windows
    for(int i = K; i < size; i++) {
        // Push in the result if queue is not empty
        result.push_back(q.empty() ? 0 : nums[q.front()]);

        // Remove from the queue if element out of the window
        while(!q.empty() && q.front() <= i - K) {
            q.pop();
        }

        // Push in the result if its negative
        if(nums[i] < 0) {
            q.push(i);
        }
    }

    result.push_back(q.empty() ? 0 : nums[q.front()]);

    return result;
}

TEST(First_negative_in_size_K, handles_various_cases) {
    const std::vector<int> nums = {-8, 2, 3, -6, 10};
    const std::vector<int> nums2 = {12, -1, -7, 8, -15, 30, -16, -28};
    const std::vector<int> nums3 = {12, 1, 3, 5};

    EXPECT_EQ(first_negative_in_size_K(nums, 2), (std::vector<int>{-8, 0, -6, -6}));
    EXPECT_EQ(first_negative_in_size_K(nums2, 2), (std::vector<int>{-1, -1, -7, -15, -15, -16, -16}));
    EXPECT_EQ(first_negative_in_size_K(nums2, 3), (std::vector<int>{-1, -1, -7, -15, -15, -16}));
    EXPECT_EQ(first_negative_in_size_K(nums3, 2), (std::vector<int>{0, 0, 0}));
}