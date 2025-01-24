class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int i, j, n;
        n = graph.size();
        vector<vector<int>> reversed_graph(n);
        vector<int> indegree(n);
        for(i = 0; i < n; i++) {
            for(j = 0; j < graph[i].size(); j++) {
                reversed_graph[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> nodes;
        for(i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                nodes.push(i);
            }
        }
        vector<int> output;
        while(!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            output.push_back(node);
            for(int neighbour : reversed_graph[node]) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0) {
                    nodes.push(neighbour);
                }
            }
        }
        sort(output.begin(), output.end());
        return output;
    }
};
