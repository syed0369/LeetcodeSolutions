class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int i, j;
        vector<int> answer(queries.size());
        unordered_map<int, int> m;
        for(i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] == x)
                m[j++] = i;
        }
        for(i = 0; i < queries.size(); i++) {
            if(queries[i] > j)
                answer[i] = -1;
            else 
                answer[i] = m[queries[i] - 1];
        }
        return answer;
    }
};
