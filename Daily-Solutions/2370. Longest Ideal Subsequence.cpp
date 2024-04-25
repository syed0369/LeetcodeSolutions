/********************************************
Solution to LeetCode Daily Question 04-25-2024. 
Problem:
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

Solution:
For each character in s (say s[i]), find the longest ideal string by including it in the longest ideal string whose last character is in the range s[i] - k and s[i] + k. Maintain the longest lengths for each character in an array. Return the maximum value in this array.

********************************************/
class Solution {
public:
    int longestIdealString(string s, int k) {
        int i, j;
        int l, r;
        int maxlength;
        vector<int> alpha(26, 0);
        maxlength = 0;
        for(i = 0; i < s.length(); i++) {
            l = s[i] - 'a' - k;
            r = s[i] - 'a' + k;
            for(j = max(l, 0); j <= min(r, 25); j++)
                alpha[s[i] - 'a'] = max(alpha[s[i] - 'a'], alpha[j]);
            maxlength = max(maxlength, ++alpha[s[i] - 'a']);
        }
        return maxlength;
    }
};
