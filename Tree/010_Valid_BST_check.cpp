#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

bool valid_BST_check_helper(std::unique_ptr<Tree_Node>& T, std::optional<int> minimum, std::optional<int> maximum) {
    if(!T) {
        return true;
    }

    if((minimum && T->data <= *minimum) || (maximum && T->data >= *maximum)) {
        return false;
    }

    return valid_BST_check_helper(T->left, minimum, T->data) && valid_BST_check_helper(T->right, T->data, maximum);
}

bool valid_BST_check(std::unique_ptr<Tree_Node>& T) {
    return valid_BST_check_helper(T, std::nullopt, std::nullopt);
}

TEST(Valid_BST_check, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(2);
    root->left = std::make_unique<Tree_Node>(1);
    root->right = std::make_unique<Tree_Node>(3);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(5);
    root2->left = std::make_unique<Tree_Node>(1);
    root2->right = std::make_unique<Tree_Node>(4);
    root2->right->left = std::make_unique<Tree_Node>(3);
    root2->right->right = std::make_unique<Tree_Node>(6);
    
    std::unique_ptr<Tree_Node> root3 = std::make_unique<Tree_Node>(1);
    root3->left = std::make_unique<Tree_Node>(2);
    root3->right = std::make_unique<Tree_Node>(3);

    EXPECT_TRUE(valid_BST_check(root));
    EXPECT_FALSE(valid_BST_check(root2));
    EXPECT_FALSE(valid_BST_check(root3));
}