#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

int maximum_depth_of_tree(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return 0;
    }

    // If left subtree is null, you must go down right
    if(!T->left) {
        return 1 + maximum_depth_of_tree(T->right);
    }

    // If right subtree is null, you must go down left
    if(!T->right) {
        return 1 + maximum_depth_of_tree(T->left);
    }

    return 1 + std::max(maximum_depth_of_tree(T->left), maximum_depth_of_tree(T->right));
}

TEST(Maximum_depth_of_tree, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(3);
    root->left = std::make_unique<Tree_Node>(9);
    root->right = std::make_unique<Tree_Node>(20);
    root->right->left = std::make_unique<Tree_Node>(15);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(1);
    root2->left = std::make_unique<Tree_Node>(2);
    root2->right = std::make_unique<Tree_Node>(3);
    root2->right->left = std::make_unique<Tree_Node>(6);
    root2->right->right = std::make_unique<Tree_Node>(7);
    root2->right->left->left = std::make_unique<Tree_Node>(12);
    root2->right->left->right = std::make_unique<Tree_Node>(13);
    root2->right->right->left = std::make_unique<Tree_Node>(14);
    root2->right->right->right = std::make_unique<Tree_Node>(15);

    EXPECT_EQ(maximum_depth_of_tree(root), 3);
    EXPECT_EQ(maximum_depth_of_tree(root2), 4);
}