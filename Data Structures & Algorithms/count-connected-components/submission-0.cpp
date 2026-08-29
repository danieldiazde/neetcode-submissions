class Solution {
private:
    void dfs(vector<bool>& visited, const vector<vector<int>>& adj, int node) {

        visited[node] = true;

        for (const auto n : adj[node]) {
            if (!visited[n]) dfs(visited, adj, n);
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.empty()) return 1;

        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); ++i) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(visited, adj, i);
                components++;
            }
        }

        return components;

    }
};
