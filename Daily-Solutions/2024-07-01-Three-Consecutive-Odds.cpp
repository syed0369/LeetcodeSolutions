/********************************************
Solution to LeetCode Daily Question 07-01-2024. 
Problem:
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

Solution:
Keep a counter to count the number of odd elements. Keep increamenting the value when an odd number is encountered. If the number is even, reset the counter. Check if the counter is 3, if yes return true. After the iteration, return false.

Time Complexity:   O(N)
Space Complexity:  O(1)

where N is size of arr.

********************************************/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i;
        int curr;
        curr = 0;
        for(i = 0; i < arr.size(); i++) {
            if(arr[i] % 2) {
                curr++;
            }
            else {
                curr = 0;
            }
            if(curr == 3)
                return true;
        }    
        return false;
    }
};
