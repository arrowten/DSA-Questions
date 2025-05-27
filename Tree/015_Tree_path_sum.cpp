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

void dfs(std::unique_ptr<Tree_Node>& T, int target, std::vector<int>& path, std::vector<std::vector<int>>& result) {
    if(!T) {
        return;
    }

    path.push_back(T->data);
    target -= T->data;

    if(!T->left && !T->right && target == 0) {
        result.push_back(path);
    }

    dfs(T->left, target, path, result);
    dfs(T->right, target, path, result);

    path.pop_back();
}

std::vector<std::vector<int>> tree_path_sum(std::unique_ptr<Tree_Node>& T, int target) {
    if(!T) {
        return {{}};
    }

    std::vector<std::vector<int>> result;
    std::vector<int> path;

    dfs(T, target, path, result);

    return result;
}

TEST(Tree_path_sum, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(5);
    root->left = std::make_unique<Tree_Node>(4);
    root->right = std::make_unique<Tree_Node>(8);
    root->left->left = std::make_unique<Tree_Node>(11);
    root->right->left = std::make_unique<Tree_Node>(13);
    root->right->right = std::make_unique<Tree_Node>(4);
    root->left->left->left = std::make_unique<Tree_Node>(7);
    root->left->left->right = std::make_unique<Tree_Node>(2);
    root->right->right->left = std::make_unique<Tree_Node>(5);
    root->right->right->right = std::make_unique<Tree_Node>(1);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(1);
    root2->left = std::make_unique<Tree_Node>(2);
    root2->right = std::make_unique<Tree_Node>(3);

    std::vector<std::vector<int>> result = {
        {5, 4, 11, 2},
        {5, 8, 4, 5}
    };
    std::vector<std::vector<int>> result2 = {};

    EXPECT_EQ(tree_path_sum(root, 22), result);
    EXPECT_EQ(tree_path_sum(root2, 5), result2);
}