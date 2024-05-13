class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int count;
        int m = grid.size();
        int n = grid[0].size();
        int score = (1 << (n - 1)) * m;
        for (int j = 1; j < n; j++) {
            count = 0;
            for (int i = 0; i < m; i++) 
                count += grid[i][j] == grid[i][0];
            score += max(count, m - count) * (1 << (n - j - 1));
        }
        return score;
    }
};
