#include <iostream>
#include <vector>
#include <memory>
#include <gtest/gtest.h>

struct Node {
    int data;
    std::shared_ptr<Node> next;

    Node(int x) : data(x), next(nullptr) {}
};

auto circular_list_check(std::shared_ptr<Node> head) {
    // Return false if head is nullptr
    if (!head) {
        return false;
    }

    std::shared_ptr<Node> slow = head;
    std::shared_ptr<Node> fast = head;

    while (fast && fast->next) {
        slow = slow->next;         // Move slow pointer one step
        fast = fast->next->next;   // Move fast pointer two steps

        // Pointers meet, which means the list is circular
        if (slow == fast) {
            return true;
        }
    }

    // If we reach here, the list is not circular
    return false;
}

// Function to convert a vector to a linked list
auto vector_to_list(const std::vector<int>& nums) {
    std::shared_ptr<Node> current = std::make_shared<Node>(0);
    std::shared_ptr<Node> dummy = current;

    for (int i : nums) {
        dummy->next = std::make_shared<Node>(i);
        dummy = dummy->next;
    }

    return current->next;
}

void make_circular(std::shared_ptr<Node> head) {
    if (!head) return;

    std::shared_ptr<Node> current = head;
    
    // Traverse to the last node
    while (current->next) {
        current = current->next;
    }

    // Make the last node point back to the first node
    current->next = head;
}

void test(const std::vector<int>& head_array, bool expected) {    
    std::shared_ptr<Node> head = vector_to_list(head_array);

    if(expected) {
        make_circular(head);
    }

    bool result = circular_list_check(head);

    EXPECT_EQ(result, expected);
}

TEST(Circular_list_check, handles_various_cases) {
    test({1, 2, 3, 4, 5}, false);
    test({1, 2, 3, 4}, true);
}