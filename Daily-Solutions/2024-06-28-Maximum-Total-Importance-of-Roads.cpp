/********************************************
Solution to LeetCode Daily Question 06-28-2024. 
Problem:
You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.
Return the maximum total importance of all roads possible after assigning the values optimally.

Solution:
The maximum total importance will be reached if the cities with maximum degrees have larger value. Count the degree of each city. Sort it. For the maximum city assign n and so on. The sum of the product of the degrees of the cities and the values will be the maximum importance of the roads.

Time Complexity:   O(Nlog N + N^2)
Space Complexity:  O(log N)

where N is number of cities.

********************************************/
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
