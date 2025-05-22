#include <iostream>
#include <stack>
#include <gtest/gtest.h>

bool balanced_parentheses_check(std::string s) {
    std::stack<char> c_stack;

    for(char c: s) {
        if(c == '(') {
            c_stack.push(')');
        }
        else if(c == '{') {
            c_stack.push('}');
        }
        else if(c == '[') {
            c_stack.push(']');
        }
        else {
            if(c_stack.empty() || c_stack.top() != c) {
                return false;
            }

            c_stack.pop();
        }
    }

    return c_stack.empty();
}

TEST(Balanced_parentheses_check, handles_various_cases) {
    const std::string s = "()", s2 = "()[]{}", s3 = "(]", s4 = "([])";

    EXPECT_TRUE(balanced_parentheses_check(s));
    EXPECT_TRUE(balanced_parentheses_check(s2));
    EXPECT_FALSE(balanced_parentheses_check(s3));
    EXPECT_TRUE(balanced_parentheses_check(s4));
}