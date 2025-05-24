#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

int maximal_square_size_in_matrix(const std::vector<std::vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> dp(M, std::vector<int>(N, 0));    // Create a DP matrix initialised to 0
    int maximum_side = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(matrix[i][j] == '1') {
                if(i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }

                maximum_side = std::max(maximum_side, dp[i][j]);
            }
        }
    }

    return maximum_side * maximum_side;
}

TEST(Maximal_square_size_in_matrix, handles_various_cases) {
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

    EXPECT_EQ(maximal_square_size_in_matrix(matrix), 4);
    EXPECT_EQ(maximal_square_size_in_matrix(matrix2), 9);
}