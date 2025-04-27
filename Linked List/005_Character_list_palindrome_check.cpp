#include <iostream>
#include <string>
#include <memory>
#include <gtest/gtest.h>

struct Node {
    char data;
    std::shared_ptr<Node> next;

    Node(char x): data(x), next(nullptr) {}
};

auto palindrome_list_check(std::shared_ptr<Node> head) {
    // Return true is head is nullptr
    if(!head) {
        return true;
    }
    
    std::string s;

    // Get all the characters in the list into a string
    while(head) {
        s.push_back(head->data);
        head = head->next;
    }

    int size = s.size();
    int l = 0, r = size - 1;

    // Check if string is palindrome
    while(l < r) {
        if(s[l++] != s[r--]) {
            return false;
        }
    }

    return true;
}

//Function to convert a vector to a linked list
auto vector_to_list(const std::vector<char>& nums) {
    std::shared_ptr<Node> current = std::make_shared<Node>(0);
    std::shared_ptr<Node> dummy = current;

    for(char i: nums) {
        dummy->next = std::make_shared<Node>(i);
        dummy = dummy->next;
    }

    return current->next;
}

void test(const std::vector<char>& character_array, bool expected) {    
    std::shared_ptr<Node> head = vector_to_list(character_array);
    bool result = palindrome_list_check(head);

    EXPECT_EQ(result, expected);
}

TEST(Character_list_palindrome_check, handles_various_cases) {
    test({'a', 'b', 'c', 'b', 'a'}, true);
    test({'a', 'b', 'b', 'a'}, true);
    test({}, true);
}