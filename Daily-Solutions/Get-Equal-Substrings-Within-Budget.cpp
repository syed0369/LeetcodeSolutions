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
