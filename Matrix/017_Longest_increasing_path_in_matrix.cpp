#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(std::vector<std::vector<int>>& matrix, int i, int j, int M, int N, std::vector<std::vector<int>>& dp) {
    if(dp[i][j] != 0) {
        return dp[i][j];
    }

    int maximum_path = 1;

    for(auto[dx, dy]: directions) {
        int x = i + dx;
        int y = j + dy;

        if(x >= 0 && x < M && y >= 0 && y < N && matrix[x][y] > matrix[i][j]) {
            maximum_path = std::max(maximum_path, 1 + dfs(matrix, x, y, M, N, dp));
        }
    }

    return dp[i][j] = maximum_path;
}

int longest_increasing_path_in_matrix(std::vector<std::vector<int>>& matrix) {
    if(matrix.empty()) {
        return 0;
    }

    int M = matrix.size(), N = matrix[0].size();
    std::vector<std::vector<int>> dp(M, std::vector<int>(N, 0));
    int maximum_length = 0;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            maximum_length = std::max(maximum_length, dfs(matrix, i, j, M, N, dp));
        }
    }

    return maximum_length;
}

TEST(Longest_increasing_path_in_matrix, handles_various_cases) {
    std::vector<std::vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    std::vector<std::vector<int>> matrix2 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };

    EXPECT_EQ(longest_increasing_path_in_matrix(matrix), 4);
    EXPECT_EQ(longest_increasing_path_in_matrix(matrix2), 4);
}