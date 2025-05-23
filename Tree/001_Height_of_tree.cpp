#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

int height_of_tree(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return 0;
    }

    // Check the maximum height between left and right subtrees
    return (1 + std::max(height_of_tree(T->left), height_of_tree(T->right)));
}

TEST(Height_of_tree, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(10);
    root->left = std::make_unique<Tree_Node>(8);
    root->right = std::make_unique<Tree_Node>(12);
    root->right->right = std::make_unique<Tree_Node>(14);
    root->left->left = std::make_unique<Tree_Node>(16);
    root->left->left->right = std::make_unique<Tree_Node>(20);

    EXPECT_EQ(height_of_tree(root), 4);
}