class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int i;
        long long maxihappy;
        priority_queue<int> q;
        maxihappy = 0;
        for(i = 0; i < happiness.size(); i++)
            q.push(happiness[i]);
        i = 0;
        while(k--) {
            maxihappy += max(0, q.top() - i);
            q.pop();
            i++;
        }
        return maxihappy;
    }
};
