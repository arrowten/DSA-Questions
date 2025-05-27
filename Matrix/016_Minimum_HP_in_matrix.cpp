#include <iostream>
#include <vector>
#include <limits.h>
#include <gtest/gtest.h>

int minimum_HP_in_matrix(const std::vector<std::vector<int>>& dungeon) {
    if(dungeon[0].empty()) {
        return 0;
    }
    
    int M = dungeon.size(), N = dungeon[0].size();
    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, INT_MAX));
    dp[M][N - 1] = dp[M - 1][N] = 1;

    for(int i = M - 1; i >= 0; i--) {
        for(int j = N - 1; j >= 0; j--) {
            int minimum_health = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = std::max(1, minimum_health);
        }
    }

    return dp[0][0];
}

int minimum_HP_in_matrix_2(const std::vector<std::vector<int>>& dungeon) {
    if(dungeon[0].empty()) {
        return 0;
    }

    int M = dungeon.size(), N = dungeon[0].size();
    std::vector<int> dp(N + 1, INT_MAX);
    dp[N - 1] = 1;

    for(int i = M - 1; i >= 0; i--) {
        dp[N] = INT_MAX;
        
        for(int j = N - 1; j >= 0; j--) {
            int minimum_health = std::min(dp[j], dp[j + 1]) - dungeon[i][j];
            dp[j] = std::max(1, minimum_health);
        }
    }

    return dp[0];
}

TEST(Minimum_HP_in_matrix, handles_various_cases) {
    const std::vector<std::vector<int>> dungeon {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    EXPECT_EQ(minimum_HP_in_matrix(dungeon), 7);
    EXPECT_EQ(minimum_HP_in_matrix_2(dungeon), 7);
}