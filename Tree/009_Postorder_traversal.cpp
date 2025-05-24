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

void postorder_traversal(std::unique_ptr<Tree_Node>& T, std::vector<int>& result) {
    if(!T) {
        return;
    }

    postorder_traversal(T->left, result);   // Traverse the left subtree
    postorder_traversal(T->right, result);  // Traverse the right subtree

    result.push_back(T->data);              // Push the data of the current node
}

TEST(Postorder_traversal, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);
    root->left->left = std::make_unique<Tree_Node>(4);
    root->left->right = std::make_unique<Tree_Node>(5);
    root->right->left = std::make_unique<Tree_Node>(6);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::vector<int> v;
    const std::vector<int> result = {4, 5, 2, 6, 7, 3, 1};

    postorder_traversal(root, v);

    EXPECT_EQ(v, result);
}