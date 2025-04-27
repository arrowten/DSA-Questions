#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

struct Node {
    int data;
    std::shared_ptr<Node> next;

    Node(int x): data(x), next(nullptr) {}
};

auto merge_2_sorted_lists(std::shared_ptr<Node> a, std::shared_ptr<Node> b) {
    // Return if both the lists are nullptr
    if(!a && !b) return std::shared_ptr<Node>();
    else if(!a) return b;
    else if(!b) return a;

    std::shared_ptr<Node> result = std::make_shared<Node>(0);
    std::shared_ptr<Node> dummy = result;

    // Iterate through the nodes together
    while(a && b) {
        if(a->data <= b->data) {
            dummy->next = std::make_shared<Node>(a->data);
            a = a->next;
        }
        else {
            dummy->next = std::make_shared<Node>(b->data);
            b = b->next;
        }
        
        dummy = dummy->next;
    }

    // Iterate through the nodes individually, if left
    while(a) {
        dummy->next = std::make_shared<Node>(a->data);
        a = a->next;
        dummy = dummy->next;
    }
    
    // Iterate through the nodes individually, if left
    while(b) {
        dummy->next = std::make_shared<Node>(b->data);
        b = b->next;
        dummy = dummy->next;
    }

    return result->next;
}

// Function to convert a vector to a linked list
auto vector_to_list(const std::vector<int>& nums) {
    std::shared_ptr<Node> current = std::make_shared<Node>(0);
    std::shared_ptr<Node> dummy = current;

    for(int i: nums) {
        dummy->next = std::make_shared<Node>(i);
        dummy = dummy->next;
    }

    return current->next;
}

// Function to convert a linked list to a vector
auto list_to_vector(std::shared_ptr<Node> node) {
    std::vector<int> result;

    while(node) {
        result.push_back(node->data);
        node = node->next;
    }

    return result;
}

void test(const std::vector<int>& a_array, const std::vector<int>& b_array, const std::vector<int>& expected_array) {    
    std::shared_ptr<Node> a = vector_to_list(a_array);
    std::shared_ptr<Node> b = vector_to_list(b_array);
    std::shared_ptr<Node> result = merge_2_sorted_lists(a, b);
    std::vector<int> result_array = list_to_vector(result);

    EXPECT_EQ(result_array, expected_array);
}

TEST(Merge_2_sorted_lists, handles_various_cases) {
    test({1, 2, 4}, {1, 3, 4}, {1, 1, 2, 3, 4, 4});
    test({}, {0}, {0});
    test({}, {}, {});
}