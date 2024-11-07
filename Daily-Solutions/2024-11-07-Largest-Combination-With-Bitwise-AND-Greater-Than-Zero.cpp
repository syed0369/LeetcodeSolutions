class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int i, n;
        int max_count, count;
        n = candidates.size();
        max_count = 0;
        for(i = 0; i < 24; i++) {
            count = 0;
            for(auto ele : candidates) {
                if(ele & (1 << i))
                    count++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};
