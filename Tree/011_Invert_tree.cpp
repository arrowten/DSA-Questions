#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

std::unique_ptr<Tree_Node> invert_tree(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return nullptr;
    }

    // Recursively invert left and right subtrees
    std::unique_ptr<Tree_Node> left_inverted = invert_tree(T->left);
    std::unique_ptr<Tree_Node> right_inverted = invert_tree(T->right);
    // Swap the left and right children
    T->left = std::move(right_inverted);
    T->right = std::move(left_inverted);

    return std::move(T);
}

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

TEST(Invert_tree, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(20);
    root->left = std::make_unique<Tree_Node>(12);
    root->right = std::make_unique<Tree_Node>(14);
    root->left->left = std::make_unique<Tree_Node>(16);
    root->left->right = std::make_unique<Tree_Node>(18);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(20);
    root2->left = std::make_unique<Tree_Node>(14);
    root2->right = std::make_unique<Tree_Node>(12);
    root2->right->left = std::make_unique<Tree_Node>(18);
    root2->right->right = std::make_unique<Tree_Node>(16);

    root = invert_tree(root);

    EXPECT_TRUE(identical_trees_check(root, root2));
}