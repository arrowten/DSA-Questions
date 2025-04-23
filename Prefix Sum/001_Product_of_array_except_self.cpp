#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<int> product_of_array_except_self(const std::vector<int>& nums) {
    if(nums.size() == 0) {
        return {};
    }

    int size = nums.size();
    std::vector<int> result(size, 1);
    int left_product = 1, right_product = 1;

    // Compute the prefix product from the left side
    for(int i = 1; i < size; i++) {
        left_product *= nums[i - 1];
        result[i] *= left_product;
    }

    // Compute the prefix product from the right side
    for(int i = size - 2; i >= 0; i--) {
        right_product *= nums[i + 1];
        result[i] *= right_product;
    }

    return result;
}

TEST(Product_of_array_except_self, handles_various_cases) {
    const std::vector<int> nums = {1, 2, 3, 4};
    const std::vector<int> nums2 = {-1, 1, 0, -3, 3};

    EXPECT_EQ(product_of_array_except_self(nums), (std::vector<int>{24, 12, 8, 6}));
    EXPECT_EQ(product_of_array_except_self(nums2), (std::vector<int>{0, 0, 9, 0, 0}));
}