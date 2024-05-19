class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int i;
        for(i = 1; i < nums.size(); i++)
            if(nums[i] % 2 == nums[i - 1] % 2)
                return false;
        return true;
    }
};
