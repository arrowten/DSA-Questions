#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<std::vector<int>> rotate_matrix_180_degrees(const std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> rotated(M, std::vector<int>(N, -1));

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            rotated[M - 1 - i][N - 1 - j] = matrix[i][j];
        }
    }

    return rotated;
}

TEST(Rotate_matrix_180_degrees, handles_various_cases) {
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
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };
    const std::vector<std::vector<int>> rotated2 {
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    EXPECT_EQ(rotate_matrix_180_degrees(matrix), rotated);
    EXPECT_EQ(rotate_matrix_180_degrees(matrix2), rotated2);
}