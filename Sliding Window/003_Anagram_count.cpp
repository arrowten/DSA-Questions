#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// Both s and t are alphabetical strings
int anagram_count(const std::string& s, const std::string& t) {
    if(s.size() == 0 || t.size() == 0 || t.size() > s.size()) return 0;

    std::vector<int> s_frequency(26, 0), t_frequency(26, 0);
    int size = s.size();    // word size
    int K = t.size();       // text size
    int count = 0;

    // Process the K characters in both the strings
    for(int i = 0; i < K; i++) {
        t_frequency[t[i] - 'a']++;
        s_frequency[s[i] - 'a']++;
    }

    if(s_frequency == t_frequency) count++;

    // Process the characters in the remaining word
    for(int i = K; i < size; i++) {
        s_frequency[s[i] - 'a']++;
        s_frequency[s[i - K] - 'a']--;

        if(s_frequency == t_frequency) count++;
    }

    return count;
}

TEST(Anagram_count, handles_various_cases) {
    const std::string s = "forxxorfxdofr", t = "for";
    const std::string s2 = "aabaabaa", t2 = "aaba";

    EXPECT_EQ(anagram_count(s, t), 3);
    EXPECT_EQ(anagram_count(s2, t2), 4);
}