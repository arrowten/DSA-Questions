#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

bool tree_path_sum_check(std::unique_ptr<Tree_Node>& T, int target) {
    if(!T) {
        return false;
    }
    
    if(!T->left && !T->right) {
        return target == T->data;
    }

    int remaining = target - T->data;

    // Recursively check for remaining sum in left and right subtrees
    return tree_path_sum_check(T->left, remaining) || tree_path_sum_check(T->right, remaining);
}

TEST(Tree_path_sum_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(5);
    root->left = std::make_unique<Tree_Node>(4);
    root->right = std::make_unique<Tree_Node>(8);
    root->left->left = std::make_unique<Tree_Node>(11);
    root->right->left = std::make_unique<Tree_Node>(13);
    root->right->right = std::make_unique<Tree_Node>(4);
    root->left->left->left = std::make_unique<Tree_Node>(7);
    root->left->left->right = std::make_unique<Tree_Node>(2);
    root->right->right->right = std::make_unique<Tree_Node>(4);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(1);
    root2->left = std::make_unique<Tree_Node>(2);
    root2->right = std::make_unique<Tree_Node>(3);

    EXPECT_TRUE(tree_path_sum_check(root, 22));
    EXPECT_FALSE(tree_path_sum_check(root2, 5));
}