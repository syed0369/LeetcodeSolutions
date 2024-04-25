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
