class Solution {
public:
    string makeFancyString(string s) {
        int i, j, n;
        string ans;
        j = 0;
        n = s.length();
        ans = "";
        for(i = 0; i < n; i++) {
            if(j < 2) {
                ans += s[i];
                j++;
            }
            else if(ans[j - 1] != s[i] || ans[j - 2] != s[i]) {
                ans += s[i];
                j++;
            }
        }
        return ans;
    }
};
