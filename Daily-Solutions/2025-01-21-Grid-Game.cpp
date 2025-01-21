class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int i, n;
        long long row1 = 0, row2 = 0, points = LONG_LONG_MAX;
        n = grid[0].size();
        row1 = row2 = 0;
        for(i = 0; i < n; i++) {
            row1 += grid[0][i];
        }
        for(i = 0; i < n; i++) {
            row1 -= grid[0][i];
            points = min(points, max(row1, row2));
            row2 += grid[1][i];
        }
        return points;
    }
};
