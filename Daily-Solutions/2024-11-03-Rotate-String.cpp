class Solution {
public:
    bool rotateString(string s, string goal) {
        int i, j, n, m;
        n = s.length();
        m = goal.length();
        if(n != m)
            return false;
        for(i = 0; i < n; i++) {
            j = 0;
            while(j < m) {
                if(s[(i + j) % n] != goal[j])
                    break;
                j++;
            }
            if(j == m)
                return true;
        }
        return false;
    }
};
