
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i;
        int x;
        unordered_map<int, int> freq;
        for(i = 0; i < nums.size(); i++) {
            freq[min(nums[i], (int)nums.size())]++;
        }
        x = 0;
        for(i = nums.size(); i >= 1; i--) {
            x += freq[i];
            if(x == i)
                return x;
        }
        return -1;
    }
};
