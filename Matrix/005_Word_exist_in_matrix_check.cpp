#include <iostream>
#include <vector>
#include <gtest/gtest.h>

bool dfs(std::vector<std::vector<char>>& matrix, std::string word, int i, int j, int index, int M, int N) {
    if(index == word.size()) {
        return true;
    }

    if(i < 0 || i >= M || j < 0 || j >= N || matrix[i][j] != word[index]) {
        return false;
    }

    char c = matrix[i][j];
    matrix[i][j] = '#';     // Mark visited

    bool found = dfs(matrix, word, i + 1, j, index + 1, M, N) ||
                dfs(matrix, word, i - 1, j, index + 1, M, N) ||
                dfs(matrix, word, i, j + 1, index + 1, M, N) ||
                dfs(matrix, word, i, j - 1, index + 1, M, N);
    
    matrix[i][j] = c;       // For backtrack

    return found;
}

bool word_exist_in_matrix_check(std::vector<std::vector<char>>& matrix, std::string word) {
    int M = matrix.size(), N = matrix[0].size();

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(dfs(matrix, word, i, j, 0, M, N)) {
                return true;
            }
        }
    }

    return false;
}

TEST(Word_exist_in_matrix_check, handles_various_cases) {
    std::vector<std::vector<char>> matrix {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'},
    };

    EXPECT_TRUE(word_exist_in_matrix_check(matrix, "ABCCED"));
    EXPECT_TRUE(word_exist_in_matrix_check(matrix, "SEE"));
    EXPECT_FALSE(word_exist_in_matrix_check(matrix, "ABCB"));
}