class Solution {
private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int parent, int node) {

        if (visited[node]) return false;
        visited[node] = true;
        for (const auto neighbour : adj[node]) {
            if (neighbour != parent && !dfs(adj, visited, node, neighbour)) return false;
        }
        return true;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //if you revisit a node that is not your parent  it is 

        if (n == 1 && edges.empty()) return true;

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < edges.size(); ++i) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }

        if (!dfs(adj, visited, -1, edges[0][0])) return false;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) return false;
        }

        return true;

    }
};
