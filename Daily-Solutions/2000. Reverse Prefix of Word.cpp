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
