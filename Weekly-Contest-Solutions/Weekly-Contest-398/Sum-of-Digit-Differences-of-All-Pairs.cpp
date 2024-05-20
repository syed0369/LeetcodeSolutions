/******************************************** 
Problem:
You are given an array nums consisting of positive integers where all integers have the same number of digits.

The digit difference between two integers is the count of different digits that are in the same position in the two integers.

Return the sum of the digit differences between all pairs of integers in nums.

Solution:
On observing many examples, we can come to the conclusion that the total number of pairs that can be formed from n numbers are nC2. To find the pairs with different digit at a place value we can subtract the same digits in the place value from nC2. This can be done by maintaining a frequency table for digits 0 to 9. For eah frequecy then the number of pairs with like digits will be frequencyC2. This is subtracted from the total number of pairs of different numbers.

Time Complexity:   O(N * number of digits)
Space Complexity:  O(1)

where N is number of elements.

********************************************/
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int i, j, pos;
        int x, count;
        long long totalpairs, samepairs;
        pos = 1;
        x = nums[0];
        count = 0;
        samepairs = 0;
        while(x) {
            count++;
            x /= 10;
        }
        totalpairs = 1LL * nums.size() * (nums.size() - 1) * count / 2;
        while(count--) {
            int freq[10] = {0};
            for(i = 0; i < nums.size(); i++) {
                freq[nums[i] / pos % 10]++;
            }
            for(i = 0; i < 10; i++) {
                samepairs += freq[i] * (freq[i] - 1) / 2;
            }
            pos *= 10;
        }
        return totalpairs - samepairs;
    }
};
