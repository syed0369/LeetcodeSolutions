/********************************************
Solution to LeetCode Daily Question 05-01-2024. 
Problem:
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

Solution:
Find the index of the character ch in the string word. If not present, return orignal string word else reverse the string till the index of the character ch.

Time Complexity:   O(N)
Space Complexity:  O(1)

where N is length of string.

********************************************/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i;
        for (i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                reverse(word.begin(), word.begin() + i + 1);
                return word;
            }
        }
        return word;
    }
};
