/********************************************
Solution to LeetCode Daily Question 06-06-2024. 
Problem:
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

Solution:
Maintain a frequency table of all the numbers. Starting with the smallest elements find if a valid group with consecutive elements can be formed. This can be done by checking for the presence of the next k - 1 elements from the starting element of the current group. 

Time Complexity:   O(NlongN)
Space Complexity:  O(N)

where N is size of hand vector.

********************************************/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int i, k;
        map<int, int> count;
        if(hand.size() % groupSize)
            return false;
        k = groupSize;
        for(i = 0; i < hand.size(); i++)
            count[hand[i]]++;
        for(auto& ele: count) {
            if(ele.second > 0) {
                for(i = k - 1; i >= 0; i--) {
                    if((count[ele.first + i] -= ele.second) < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
