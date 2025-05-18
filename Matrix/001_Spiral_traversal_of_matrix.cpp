#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<int> spiral_traversal_of_matrix(const std::vector<std::vector<int>>& matrix) {
    int M = matrix.size(), N = matrix[0].size();
    int top = 0, bottom = M - 1, left = 0, right = N - 1;
    std::vector<int> result;
    
    // Until the loop exists, there are elements left
    while(top <= bottom && left <= right) {
        // Top row left to right traversal
        for(int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }

        top++;

        // Right column top to bottom traversal
        for(int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }

        right--;

        // Bottom left to right traversal (if it exists)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }

            bottom--;
        }

        // Left bottom to top traversal (if it exists)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }

            left++;
        }
    }

    return result;
}

TEST(Spiral_traversal_of_matrix, handles_various_cases) {
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

    const std::vector<int> result = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
    const std::vector<int> result2 = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

    EXPECT_EQ(spiral_traversal_of_matrix(matrix), result);
    EXPECT_EQ(spiral_traversal_of_matrix(matrix2), result2);
}