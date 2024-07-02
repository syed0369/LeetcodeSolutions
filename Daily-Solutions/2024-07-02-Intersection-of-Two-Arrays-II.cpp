/********************************************
Solution to LeetCode Daily Question 02-07-2024. 
Problem:
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Solution:
Maintain a frequency table for elements of num1, using this check if there are common elements in num2 which is indicated by a positive value in the map freq.

Time Complexity:   O(N + M)
Space Complexity:  O(N)

where N is size of nums1 and M is the size of nums2.

********************************************/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int i;
        vector<int> intersection;
        unordered_map<int, int> freq;
        for(i = 0; i < nums1.size(); i++) {
            freq[nums1[i]]++;
        }
        for(i = 0; i < nums2.size(); i++) {
            if(freq[nums2[i]]) {
                intersection.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        return intersection;
    }
};
