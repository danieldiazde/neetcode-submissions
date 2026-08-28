class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, int parent, vector<bool>& visited, int node) {
        visited[node] = true;

        for (const int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (hasCycle(adj, node, visited, neighbour)) return true;
            }
            else if (neighbour != parent) return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 1 && edges.empty()) return true;
        vector<bool> visited(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < (int)edges.size(); ++i) {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            adj[node1].push_back(node2);
            adj[node2].push_back(node1);
        }

        if (hasCycle(adj, -1, visited, adj[0][0])) return false;
        for (bool v : visited) if (!v) return false;

        return true;
    }
};
