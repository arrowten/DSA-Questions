#include <iostream>
#include <memory>
#include <gtest/gtest.h>

struct Tree_Node {
    int data;
    std::unique_ptr<Tree_Node> left;
    std::unique_ptr<Tree_Node> right;

    Tree_Node(int x): data(x), left(nullptr), right(nullptr) {}
};

std::unique_ptr<Tree_Node> find_minimum(std::unique_ptr<Tree_Node>& T) {
    while(T->left) {
        T = std::move(T->left);
    }

    return std::move(T);
}

std::unique_ptr<Tree_Node> delete_node_in_BST(std::unique_ptr<Tree_Node>& T, int key) {
    if(!T) {
        return nullptr;
    }

    if(key < T->data) {
        T->left = delete_node_in_BST(T->left, key);
    }
    else if(key > T->data) {
        T->right = delete_node_in_BST(T->right, key);
    }
    else {
        if(!T->left) {
            T = std::move(T->right);
        }
        else if(!T->right) {
            T = std::move(T->left);
        }
        else {
            std::unique_ptr<Tree_Node> node = find_minimum(T->right);
            T->data = node->data;

            T->right = delete_node_in_BST(T->right, node->data);
        }
    }

    return std::move(T);
}

void delete_node_in_BST_2(std::unique_ptr<Tree_Node>& T, int key) {
    if(!T) {
        return;
    }

    if(key < T->data) {
        delete_node_in_BST_2(T->left, key);
    }
    else if(key > T->data) {
        delete_node_in_BST_2(T->right, key);
    }
    else {
        if(!T->left) {
            T = std::move(T->right);
        }
        else if(!T->right) {
            T = std::move(T->left);
        }
        else {
            std::unique_ptr<Tree_Node> node = find_minimum(T->right);
            T->data = node->data;

            delete_node_in_BST_2(T->right, node->data);
        }
    }
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

TEST(Delete_node_in_BST, handles_various_cases) {
    std::unique_ptr<Tree_Node> root = std::make_unique<Tree_Node>(5);
    root->left = std::make_unique<Tree_Node>(3);
    root->right = std::make_unique<Tree_Node>(6);
    root->left->left = std::make_unique<Tree_Node>(2);
    root->left->right = std::make_unique<Tree_Node>(4);
    root->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> root2 = std::make_unique<Tree_Node>(5);
    root2->left = std::make_unique<Tree_Node>(3);
    root2->right = std::make_unique<Tree_Node>(6);
    root2->left->left = std::make_unique<Tree_Node>(2);
    root2->left->right = std::make_unique<Tree_Node>(4);
    root2->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> root3 = std::make_unique<Tree_Node>(5);
    root3->left = std::make_unique<Tree_Node>(4);
    root3->right = std::make_unique<Tree_Node>(6);
    root3->left->left = std::make_unique<Tree_Node>(2);
    root3->right->right = std::make_unique<Tree_Node>(7);

    std::unique_ptr<Tree_Node> root4 = std::make_unique<Tree_Node>(5);
    root4->left = std::make_unique<Tree_Node>(4);
    root4->right = std::make_unique<Tree_Node>(6);
    root4->left->left = std::make_unique<Tree_Node>(2);
    root4->right->right = std::make_unique<Tree_Node>(7);

    root = delete_node_in_BST(root, 3);
    delete_node_in_BST_2(root2, 3);

    EXPECT_TRUE(identical_trees_check(root, root3));
    EXPECT_TRUE(identical_trees_check(root2, root4));
}