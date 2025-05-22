#include <iostream>
#include <vector>
#include <gtest/gtest.h>

void rotate_square_matrix_90_degrees_clockwise(std::vector<std::vector<int>>& matrix) {
    int N = matrix.size();

    // Transpose the matrix
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < N; i++) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

TEST(Rotate_square_matrix_90_degrees_clockwise, handles_various_cases) {
    std::vector<std::vector<int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    std::vector<std::vector<int>> matrix2 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    const std::vector<std::vector<int>> rotated {
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4}  
    };
    const std::vector<std::vector<int>> rotated2 {
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3}  
    };

    rotate_square_matrix_90_degrees_clockwise(matrix);
    rotate_square_matrix_90_degrees_clockwise(matrix2);

    EXPECT_EQ(matrix, rotated);
    EXPECT_EQ(matrix2, rotated2);
}