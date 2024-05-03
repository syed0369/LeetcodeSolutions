/********************************************
Solution to LeetCode Daily Question 05-02-2024. 
Problem:
Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.

Return the positive integer k. If there is no such integer, return -1.

Solution:
Create a hash table with the elements as the keys and assign 1 value if the element is present. For each element also check if its negative is present in the hash table and compare the value with current maximum. This can be done in a single pass.

Time Complexity:   O(N) average time for access incase of unordered_map is in constant time, if map used then O(log n)
Space Complexity:  O(1) 

where N is length of string.

********************************************/
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
