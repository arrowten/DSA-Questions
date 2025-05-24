#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

void inorder_traversal(std::unique_ptr<Tree_Node>& T, std::vector<int>& result) {
    if(!T) {
        return;
    }

    inorder_traversal(T->left, result);     // Traverse the left subtree

    result.push_back(T->data);              // Push the data of the current node
    
    inorder_traversal(T->right, result);    // Traverse the right subtree
}

TEST(Inorder_traversal, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);
    root->left->left = std::make_unique<Tree_Node>(4);
    root->left->right = std::make_unique<Tree_Node>(5);
    root->right->left = std::make_unique<Tree_Node>(6);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::vector<int> v;
    const std::vector<int> result = {4, 2, 5, 1, 6, 3, 7};

    inorder_traversal(root, v);

    EXPECT_EQ(v, result);
}