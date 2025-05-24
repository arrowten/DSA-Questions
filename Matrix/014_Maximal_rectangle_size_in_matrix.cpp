#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int maximal_rectangle_size_in_matrix(const std::vector<std::vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> new_matrix(M, std::vector<int>(N, 0));
    int maximum_area = 0;

    // Step 1: Precompute new_matrix[i][j] = number of consecutive 1s to the left (including current) 
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(matrix[i][j] == '1') {
                new_matrix[i][j] = (j == 0 ? 1 : new_matrix[i][j - 1] + 1);
            }
        }
    }

    // Step 2: For each cell, treat it as the bottom right corner
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(matrix[i][j] == '0') {
                continue;
            }

            int minimum_width = new_matrix[i][j];

            // Go upward from row i to 0
            for(int k = i; k >= 0; k--) {
                if(new_matrix[k][j] == 0) {
                    break;
                }
                
                minimum_width = std::min(minimum_width, new_matrix[k][j]);
                int height = i - k + 1;
                maximum_area = std::max(maximum_area, height * minimum_width);
            }
        }
    }

    return maximum_area;
}

TEST(Maximal_rectangle_size_in_matrix, handles_various_cases) {
    const std::vector<std::vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    const std::vector<std::vector<char>> matrix2 = {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };

    EXPECT_EQ(maximal_rectangle_size_in_matrix(matrix), 6);
    EXPECT_EQ(maximal_rectangle_size_in_matrix(matrix2), 9);
}