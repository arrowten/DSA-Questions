#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

std::vector<int> right_side_view_of_tree(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return {};
    }
    
    std::queue<std::reference_wrapper<std::unique_ptr<Tree_Node>>> q;
    std::vector<int> result;
    q.push(T);

    while(!q.empty()) {
        int level_size = q.size();

        for(int i = 0; i < level_size; i++) {
            auto& current = q.front().get();
            q.pop();

            if(i == level_size - 1) {
                result.push_back(current->data);
            }

            if(current->left) {
                q.push(current->left);
            }

            if(current->right) {
                q.push(current->right);
            }
        }
    }

    return result;
}

TEST(Right_side_view_of_tree, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);
    root->left->left = std::make_unique<Tree_Node>(4);
    root->left->right = std::make_unique<Tree_Node>(5);
    root->right->left = std::make_unique<Tree_Node>(6);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(1);
    root2->left = std::make_unique<Tree_Node>(2);
    root2->right = std::make_unique<Tree_Node>(3);
    root2->left->right = std::make_unique<Tree_Node>(5);
    root2->right->left = std::make_unique<Tree_Node>(6);

    const std::vector<int> result = {1, 3, 7};
    const std::vector<int> result2 = {1, 3, 6};

    EXPECT_EQ(right_side_view_of_tree(root), result);
    EXPECT_EQ(right_side_view_of_tree(root2), result2);
}