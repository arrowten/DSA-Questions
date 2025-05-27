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

std::vector<std::vector<int>> level_order_bottom_traversal(std::unique_ptr<Tree_Node>& T) {
    if(!T) {
        return {{}};
    }

    std::queue<std::reference_wrapper<std::unique_ptr<Tree_Node>>> q;
    std::vector<std::vector<int>> result;
    q.push(T);

    while(!q.empty()) {
        int level_size = q.size();
        std::vector<int> current_level;
        
        for(int i = 0; i < level_size; i++) {
            auto& current = q.front().get();
            current_level.push_back(current->data);
            q.pop();

            if(current->left) {
                q.push(current->left);
            }

            if(current->right) {
                q.push(current->right);
            }
        }

        result.push_back(current_level);
    }

    std::reverse(result.begin(), result.end());
    
    return result;
}

TEST(Level_order_bottom_traversal, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(1);
    root->left = std::make_unique<Tree_Node>(2);
    root->right = std::make_unique<Tree_Node>(3);
    root->left->left = std::make_unique<Tree_Node>(4);
    root->left->right = std::make_unique<Tree_Node>(5);
    root->right->left = std::make_unique<Tree_Node>(6);
    root->right->right = std::make_unique<Tree_Node>(7);

    const std::vector<std::vector<int>> result = {
        {4, 5, 6, 7},
        {2, 3},
        {1}
    };

    EXPECT_EQ(level_order_bottom_traversal(root), result);
}