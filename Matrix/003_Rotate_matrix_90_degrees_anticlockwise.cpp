#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<std::vector<int>> rotate_matrix_90_degrees_anticlockwise(const std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> rotated(N, std::vector<int>(M, -1));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            rotated[N - 1- j][i] = matrix[i][j];
        }
    }

    return rotated;
}

TEST(Rotate_matrix_90_degrees_anticlockwise, handles_various_cases) {
    const std::vector<std::vector<int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    const std::vector<std::vector<int>> matrix2 {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    const std::vector<std::vector<int>> rotated {
        {4, 8, 12, 16},
        {3, 7, 11, 15},
        {2, 6, 10, 14},
        {1, 5, 9, 13}  
    };
    const std::vector<std::vector<int>> rotated2 {
        {4, 8, 12},
        {3, 7, 11},
        {2, 6, 10},
        {1, 5, 9}
    };

    EXPECT_EQ(rotate_matrix_90_degrees_anticlockwise(matrix), rotated);
    EXPECT_EQ(rotate_matrix_90_degrees_anticlockwise(matrix2), rotated2);
}