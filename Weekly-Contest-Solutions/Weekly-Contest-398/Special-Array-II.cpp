/******************************************** 
Problem:
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

Solution:
The Brute force can be to check if each subarry whose ends are given in queries is special or not. Time complexity will be O(N * Q) which results in TLE. The optimum approach can be to maintain a prefix sum array whose i th element will be the number of pairs with same parity till i th element. Then the range [l, r] given in queries will be special if there was such a pair with different parity which means the prefix sum of the r - 1 th and l - 1 th elements should be zero else there was a pair with same parity hence not a special array.

Time Complexity:   O(N + Q)
Space Complexity:  O(N + Q)

where N is number of elements and Q is the number of queries.

********************************************/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int i;
        int l, r;
        vector<int> prefixsum(nums.size());
        vector<bool> v(queries.size(), true);
        
        for(i = 0; i < nums.size() - 1; i++) {
            prefixsum[i] += (nums[i + 1] % 2) == (nums[i] % 2);
            prefixsum[i + 1] += prefixsum[i];    
        }
        for(i = 0; i < queries.size(); i++) {
            l = queries[i][0];
            r = queries[i][1];
            if(l == 0 && r == 0)
                v[i] = true;
            else if(l == 0)
                v[i] = ((prefixsum[r - 1])? false : true);
            else 
                v[i] = ((prefixsum[r - 1] - prefixsum[l - 1])? false : true);
        }
        
        return v;
    }
};
