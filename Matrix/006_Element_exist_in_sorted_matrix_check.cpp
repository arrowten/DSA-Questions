#include <iostream>
#include <vector>
#include <gtest/gtest.h>

bool element_exist_in_sorted_matrix_check(const std::vector<std::vector<int>>& matrix, int target) {
    int M = matrix.size(), N = matrix[0].size();
    int row = 0, column = N - 1;

    while(row < M && column >= 0) {
        if(matrix[row][column] == target) {
            return true;
        }
        else if(matrix[row][column] > target) {
            column--;   // Move left
        }
        else {
            row++;      // Move right
        }
    }

    return false;
}

TEST(Element_exist_in_sorted_matrix_check, handles_various_cases) {
    const std::vector<std::vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    EXPECT_TRUE(element_exist_in_sorted_matrix_check(matrix, 25));
    EXPECT_TRUE(element_exist_in_sorted_matrix_check(matrix, 33));
    EXPECT_FALSE(element_exist_in_sorted_matrix_check(matrix, 38));
}