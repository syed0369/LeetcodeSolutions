
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int i;
        long long importance;
        vector<int> city(n, 0);
        for(i = 0; i < roads.size(); i++) {
            city[roads[i][0]]++;
            city[roads[i][1]]++;
        }
        sort(city.begin(), city.end());
        importance = 0;
        for(i = n - 1; i >= 0; i--) {
            importance = importance + 1ll * city[i] * (i + 1);
        }
        return importance;
    }
};
