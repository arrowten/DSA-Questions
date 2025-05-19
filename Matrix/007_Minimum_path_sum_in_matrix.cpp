#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int minimum_path_sum_in_matrix(std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    
    // Fill the first row
    for(int j = 1; j < N; j++) {
        matrix[0][j] += matrix[0][j - 1];
    }
    
    // Fill the first column
    for(int i = 1; i < M; i++) {
        matrix[i][0] += matrix[i - 1][0];
    }

    // Fill the rest
    for(int i = 1; i < M; i++) {
        for(int j = 1; j < N; j++) {
            matrix[i][j] += std::min(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }

    return matrix[M - 1][N - 1];
}

TEST(Minimum_path_sum_in_matrix, handles_various_cases) {
    std::vector<std::vector<int>> matrix {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    EXPECT_EQ(minimum_path_sum_in_matrix(matrix), 7);
}