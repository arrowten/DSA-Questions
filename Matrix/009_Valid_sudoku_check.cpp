#include <iostream>
#include <vector>
#include <unordered_set>
#include <gtest/gtest.h>

bool valid_sudoku_check(const std::vector<std::vector<char>>& sudoku) {
    std::vector<std::unordered_set<char>> rows(9), columns(9), boxes(9);

    // Traverse each cell in the 9 * 9 board
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            char x = sudoku[i][j];

            // Skip empty cells
            if(x == '.') {
                continue;
            }

            // Check for duplicates in the current row
            if(rows[i].count(x)) {
                return false;
            }

            rows[i].insert(x);

            // Check for duplicates in the current column
            if(columns[i].count(x)) {
                return false;
            }

            columns[i].insert(x);

            // Calculate box index (0 to 8) for 3 * 3 sub box
            // (i / 3) gives row group (0 to 2), (j / 3) gives column group 0 - 2
            int box_index = (i / 3) * 3 + (j / 3);

            // Check for duplicates in the box
            if(boxes[box_index].count(x)) {
                return false;
            }

            boxes[box_index].insert(x);
        }
    }

    // If everything is correct, then return true
    return true;
}

TEST(Valid_sudoku_check, handles_various_cases) {
    const std::vector<std::vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    std::vector<std::vector<char>> sudoku2 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','5','.','1','9','5','.','.','.'}, // <-- Duplicate '5' in this row (index 1)
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    EXPECT_TRUE(valid_sudoku_check(sudoku));
    EXPECT_FALSE(valid_sudoku_check(sudoku2));
}