#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

bool element_exist_in_BST_check(std::unique_ptr<Tree_Node>& T, int x) {
    if(!T) {
        return false;
    }

    if(x == T->data) {
        return true;
    }
    else if(x < T->data) {  // If x is less, search in left subtree
        return element_exist_in_BST_check(T->left, x);
    }
    else {                  // If x is more, search in right subtree
        return element_exist_in_BST_check(T->right, x);
    }
}

TEST(Element_exist_in_BST_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(50);
    root->left = std::make_unique<Tree_Node>(25);
    root->left->left = std::make_unique<Tree_Node>(15);
    root->left->right = std::make_unique<Tree_Node>(35);
    root->right = std::make_unique<Tree_Node>(75);
    root->right->left = std::make_unique<Tree_Node>(65);
    root->right->right = std::make_unique<Tree_Node>(85);

    EXPECT_TRUE(element_exist_in_BST_check(root, 15));
    EXPECT_FALSE(element_exist_in_BST_check(root, 20));
}