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

bool tree_subtree_of_another_tree_check(std::unique_ptr<Tree_Node>& T, std::unique_ptr<Tree_Node>& subtree) {
    // If both are nullptr, return false
    if(!T && !subtree) {
        return false;
    }

    // If one is nullptr, return false
    if(!T || !subtree) {
        return false;
    }

    if(identical_trees_check(T, subtree)) {
        return true;
    }

    // Recursively check subtree in left and right subtrees
    return tree_subtree_of_another_tree_check(T->left, subtree) || tree_subtree_of_another_tree_check(T->right, subtree);
}

TEST(Tree_subtree_of_another_tree_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);
    root->left->left = std::make_unique<Tree_Node>(4);
    root->left->right = std::make_unique<Tree_Node>(5);
    root->right->left = std::make_unique<Tree_Node>(6);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> subtree_root = std::make_unique<Tree_Node>(3);
    subtree_root->left = std::make_unique<Tree_Node>(6);
    subtree_root->right = std::make_unique<Tree_Node>(7);

    EXPECT_TRUE(tree_subtree_of_another_tree_check(root, subtree_root));
}