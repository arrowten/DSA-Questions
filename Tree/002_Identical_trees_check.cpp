#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

bool identical_trees_check(std::unique_ptr<Tree_Node>& A, std::unique_ptr<Tree_Node>& B) {
    // If both are nullptr, return true
    if(!A && !B) {
        return true;
    }
    
    // If one is nullptr, return false
    if(!A || !B) {
        return false;
    }
    
    // Recursively check identical for left and right subtrees
    return (A->data == B->data && identical_trees_check(A->left, B->left) && identical_trees_check(A->right, B->right));
}

TEST(Identical_trees_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(10);
    root->left = std::make_unique<Tree_Node>(8);
    root->right = std::make_unique<Tree_Node>(12);
    root->right->right = std::make_unique<Tree_Node>(14);
    root->left->left = std::make_unique<Tree_Node>(16);
    root->left->left->right = std::make_unique<Tree_Node>(20);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(10);
    root2->left = std::make_unique<Tree_Node>(8);
    root2->right = std::make_unique<Tree_Node>(12);
    root2->right->right = std::make_unique<Tree_Node>(14);
    root2->left->left = std::make_unique<Tree_Node>(16);
    root2->left->left->right = std::make_unique<Tree_Node>(20);
    
    EXPECT_TRUE(identical_trees_check(root, root2));
}