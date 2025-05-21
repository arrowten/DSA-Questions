#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

void rotate_matrix_rows_by_K_elements(std::vector<std::vector<int>>& matrix, int K) {
    int N = matrix[0].size();
    K %= N;

    if(K == 0) {
        return;
    }

    // Rotate the row elements
    for(auto& row: matrix) {
        std::reverse(row.begin(), row.end());
        std::reverse(row.begin(), row.begin() + K);
        std::reverse(row.begin() + K, row.end());
    }
}

TEST(Rotate_matrix_rows_by_K_elements, handles_various_cases) {
    std::vector<std::vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    std::vector<std::vector<int>> matrix2 = {
        {8, 7, 2},
        {5, 9, 1},
        {3, 6, 4}
    };

    std::vector<std::vector<int>> result = {
        {30, 40, 10, 20},
        {35, 45, 15, 25},
        {37, 48, 27, 29},
        {39, 50, 32, 33}
    };
    std::vector<std::vector<int>> result2 = {
        {2, 8, 7},
        {1, 5, 9},
        {4, 3, 6}
    };

    rotate_matrix_rows_by_K_elements(matrix, 2);
    rotate_matrix_rows_by_K_elements(matrix2, 1);

    EXPECT_EQ(matrix, result);
    EXPECT_EQ(matrix2, result2);
}