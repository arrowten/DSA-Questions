#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

struct Node {
    int data;
    std::shared_ptr<Node> next;

    Node(int x): data(x), next(nullptr) {}
};

auto reverse_list(std::shared_ptr<Node> head) {
    // Return if head is nullptr
    if(!head) {
        return std::shared_ptr<Node>();
    }
    
    std::shared_ptr<Node> previous = nullptr, current = head, upcoming;

    // Reverse the list
    while(current) {
        upcoming = current->next;
        current->next = previous;
        previous = current;
        current = upcoming;
    }

    return previous;
}

//Function to convert a vector to a linked list
auto vector_to_list(const std::vector<int>& nums) {
    std::shared_ptr<Node> current = std::make_shared<Node>(0);
    std::shared_ptr<Node> dummy = current;

    for(int i: nums) {
        dummy->next = std::make_shared<Node>(i);
        dummy = dummy->next;
    }

    return current->next;
}

//Function to convert a linked list to a vector
auto list_to_vector(std::shared_ptr<Node> node) {
    std::vector<int> result;

    while(node) {
        result.push_back(node->data);
        node = node->next;
    }

    return result;
}

void test(const std::vector<int>& head_array, const std::vector<int>& expected_array) {    
    std::shared_ptr<Node> head = vector_to_list(head_array);
    std::shared_ptr<Node> result = reverse_list(head);
    std::vector<int> result_array = list_to_vector(result);

    EXPECT_EQ(result_array, expected_array);
}

TEST(Reverse_list, handles_various_cases) {
    test({1, 2, 3, 4, 5}, {5, 4, 3, 2, 1});
    test({6, 5, 9, 7, 8}, {8, 7, 9, 5, 6});
}