class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int i, j, n, m;
        n = mat.size();
        m = mat[0].size();
        map<int, pair<int, int>> position;
        vector<int> rows(n, m);
        vector<int> cols(m, n);

        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                position[mat[i][j]] = {i, j}; 
            }
        }
        for(i = 0; i < n * m; i++) {
            int row = position[arr[i]].first;
            int col = position[arr[i]].second;
            rows[row]--;
            cols[col]--;
            if(!rows[row] || !cols[col])
                return i;
        }
        return n * m;
    }
};
