class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i, j;
        long long count;
        unordered_map<int, int> freq;
        count = 0;
        for(i = 0; i < nums2.size(); i++)
            freq[nums2[i] * k]++; 
        for(i = 0; i < nums1.size(); i++) {
            for(j = 1; j <= sqrt(nums1[i]); j++) {
                if(nums1[i] % j == 0)
                    count += (j == nums1[i] / j) ? freq[j] : freq[j] + freq[nums1[i] / j];
            }
        }
        return count;
    }
};
