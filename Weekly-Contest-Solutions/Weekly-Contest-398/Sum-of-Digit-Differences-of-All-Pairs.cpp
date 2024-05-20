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
