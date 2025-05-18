#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<std::vector<int>> rotate_matrix_90_degrees_clockwise(const std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> rotated(N, std::vector<int>(M, -1));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            rotated[j][M - i - 1] = matrix[i][j];
        }
    }

    return rotated;
}

TEST(Rotate_matrix_90_degrees_clockwise, handles_various_cases) {
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
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}  
    };
    const std::vector<std::vector<int>> rotated2 {
        {9, 5, 1},
        {10, 6, 2},
        {11, 7, 3},
        {12, 8, 4}  
    };

    EXPECT_EQ(rotate_matrix_90_degrees_clockwise(matrix), rotated);
    EXPECT_EQ(rotate_matrix_90_degrees_clockwise(matrix2), rotated2);
}