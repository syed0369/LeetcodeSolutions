class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int i;
        int max;
        unordered_map<int, int> m;
        max = -1;
        for(i = 0; i < nums.size(); i++) {
            if(m[-nums[i]] && abs(nums[i]) > max)
                max = abs(nums[i]);
            m[nums[i]] = 1;            
        }
        return max;
    }
};
