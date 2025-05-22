#include <iostream>
#include <vector>
#include <gtest/gtest.h>

void print(std::vector<std::vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            std::cout << matrix[i][j] << '\t';
        }

        std::cout << '\n';
    }

    std::cout << "\n\n";
}

void rotate_square_matrix_90_degrees_anticlockwise(std::vector<std::vector<int>>& matrix) {
    int N = matrix.size();

    // Transpose the matrix
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    //Reverse each column
    for(int i = 0; i < N; i++) {
        int top = 0, bottom = N - 1;

        while(top < bottom) {
            std::swap(matrix[top][i], matrix[bottom][i]);
            top++; 
            bottom--;
        }
    }
}

TEST(Rotate_square_matrix_90_degrees_anticlockwise, handles_various_cases) {
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
        {4, 8, 12, 16},
        {3, 7, 11, 15},
        {2, 6, 10, 14},
        {1, 5, 9, 13}
    };
    const std::vector<std::vector<int>> rotated2 {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };

    rotate_square_matrix_90_degrees_anticlockwise(matrix);
    rotate_square_matrix_90_degrees_anticlockwise(matrix2);

    EXPECT_EQ(matrix, rotated);
    EXPECT_EQ(matrix2, rotated2);
}