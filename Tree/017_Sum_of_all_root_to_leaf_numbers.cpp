#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

int dfs(std::unique_ptr<Tree_Node>& T, int sum) {
    if(!T) {
        return 0;
    }

    sum = sum * 10 + T->data;

    if(!T->left && !T->right) {
        return sum;
    }

    return dfs(T->left, sum) + dfs(T->right, sum);
}

int sum_of_all_root_to_leaf_numbers(std::unique_ptr<Tree_Node>& T) {
    return dfs(T, 0);
}

TEST(Sum_of_all_root_to_leaf_numbers, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(4);
    root2->left = std::make_unique<Tree_Node>(9);
    root2->right = std::make_unique<Tree_Node>(0);
    root2->left->left = std::make_unique<Tree_Node>(5);
    root2->left->right = std::make_unique<Tree_Node>(1);

    EXPECT_EQ(sum_of_all_root_to_leaf_numbers(root), 25);
    EXPECT_EQ(sum_of_all_root_to_leaf_numbers(root2), 1026);
}