#include <iostream>
#include <vector>
#include <gtest/gtest.h>

std::vector<std::vector<int>> rotate_matrix_by_K_elements(std::vector<std::vector<int>>& matrix, int K) {
    int M = matrix.size(), N = matrix[0].size();
    int size = M * N;
    K %= size;

    if(K == 0) {
        return matrix;    
    }

    std::vector<int> original, shifted(size);
    std::vector<std::vector<int>> result(M, std::vector<int>(N, 0));

    // Shift the matrix elements to a vector
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            original.push_back(matrix[i][j]);
        }
    }

    // Perform the shift in vector
    for(int i = 0; i < size; i++) {
        shifted[(i + K) % size] = original[i];
    }

    // Push the elements back to the original matrix
    for(int i = 0; i < size; i++) {
        result[i / N][i % N] = shifted[i];
    }

    return result;
}

TEST(Rotate_matrix_by_K_elements, handles_various_cases) {
    std::vector<std::vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };

    std::vector<std::vector<int>> result = {
        {39, 50, 10, 20},
        {30, 40, 15, 25},
        {35, 45, 27, 29},
        {37, 48, 32, 33}
    };
    std::vector<std::vector<int>> result2 = {
        {32, 33, 39, 50},
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48}        
    };
    
    EXPECT_EQ(rotate_matrix_by_K_elements(matrix, 2), result);
    EXPECT_EQ(rotate_matrix_by_K_elements(matrix, 4), result2);
}