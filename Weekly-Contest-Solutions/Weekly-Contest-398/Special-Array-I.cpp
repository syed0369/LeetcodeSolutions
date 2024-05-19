/********************************************
Problem:
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

Solution:
Iterate through the array and check the parity adjacent elements.

Time Complexity:   O(N)
Space Complexity:  O(1)

where N is size of the vector.

********************************************/
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
