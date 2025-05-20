#include <iostream>
#include <vector>
#include <gtest/gtest.h>

void set_matrix_zeros(std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    bool first_row_zero = false, first_column_zero = false;

    // Check if the first row has any 0s
    for(int j = 0; j < N; j++) {
        if(matrix[0][j] == 0) {
            first_row_zero = true;

            break;
        }
    }
    
    // Check if the first column has any 0s
    for(int i = 0; i < M; i++) {
        if(matrix[i][0] == 0) {
            first_column_zero = true;

            break;
        }
    }

    // Use the first row and column as markers
    for(int i = 1; i < M; i++) {
        for(int j = 1; j < N; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out cells based on markers
    for(int i = 1; i < M; i++) {
        for(int j = 1; j < N; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Make the full row 0 if any one is 0
    if(first_row_zero) {
        for(int j = 0; j < N; j++) {
            matrix[0][j] = 0;
        }
    }

    // Make the full column 0 if any one is 0
    if(first_column_zero) {
        for(int i = 0; i < M; i++) {
            matrix[i][0] = 0;
        }
    }
}

TEST(Set_matrix_zeros, handles_various_cases) {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    std::vector<std::vector<int>> result = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };

    set_matrix_zeros(matrix);

    EXPECT_EQ(matrix, result);
}