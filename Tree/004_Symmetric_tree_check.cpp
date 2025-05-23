#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

bool inverted_trees_check(std::unique_ptr<Tree_Node>& A, std::unique_ptr<Tree_Node>& B) {
    // If both are nullptr, return true
    if(!A && !B) {
        return true;
    }
    
    // If one is nullptr, return false
    if(!A || !B) {
        return false;
    }

    // Recursively check inverted for left and right subtrees
    return (A->data == B->data && inverted_trees_check(A->left, B->right) && inverted_trees_check(A->right, B->left));
}

bool symmetric_tree_check(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return true;
    }

    // Check if left and right half are inverted
    return inverted_trees_check(T, T);
}

TEST(Symmetric_trees_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(10);
    root->left = std::make_unique<Tree_Node>(8);
    root->right = std::make_unique<Tree_Node>(8);
    root->left->left = std::make_unique<Tree_Node>(10);
    root->left->right = std::make_unique<Tree_Node>(12);
    root->right->left = std::make_unique<Tree_Node>(12);
    root->right->right = std::make_unique<Tree_Node>(10);
    root->left->left->left = std::make_unique<Tree_Node>(16);
    root->right->right->right = std::make_unique<Tree_Node>(16);

    EXPECT_TRUE(root);
}