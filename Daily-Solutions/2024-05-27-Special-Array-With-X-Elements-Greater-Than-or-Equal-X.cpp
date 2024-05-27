/********************************************
Solution to LeetCode Daily Question 05-27-2024. 
Problem:
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

Solution:
The value of x is in the range [1, nums.size()]. It cannot exceed nums.size() as that would mean there are more elements greater than or equal to x than actually present in nums which is absurd. Hence the presence of numbers greater than N is equivalent to N being present. The approach is to maintain a suffix frequency sum array. Find the number of elements greater or equal than current element and check if it is equal to the current element.

Time Complexity:   O(N)
Space Complexity:  O(N)

where N is size of nums.

********************************************/
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
