class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int i, exor;
        unordered_map<int, int> m;
        exor = 0;
        for(i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if(m[nums[i]] == 2)
                exor = exor ^ nums[i];
        }
        return exor;
    }
};
