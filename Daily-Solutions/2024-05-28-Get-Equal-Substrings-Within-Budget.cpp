/********************************************
Solution to LeetCode Daily Question 05-28-2024. 
Problem:
You are given two strings s and t of the same length and an integer maxCost.
You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Solution:
The maximum length subarray with cost less than equal to maxCost can be found using sliding window approach, a pointer is maintained which marks start of the subarray. The cost till current index is calculated if it exceeds the maxCost, the start pointer is moved forward until the curr cost dones not become less than the maxCost. The maxlength is updated.

Time Complexity:   O(N)
Space Complexity:  O(1)

where N is length of string.

********************************************/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i;
        int start, curr, maxlength;

        start = curr = maxlength = 0;
        for(i = 0; i < s.length(); i++) {
            curr += abs(s[i] - t[i]);
            while(curr > maxCost) {
                curr -= abs(s[start] - t[start]);
                start++;
            }
            maxlength = max(maxlength, i - start + 1);
        }
        return maxlength;
    }
};
