class Solution {
  public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& visited, vector<int>& path) {

        visited[node] = 1;
        path[node] = 1;

        for (int neighbor : adj[node]) {

            // Not visited
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, path))
                    return true;
            }

            // Already in current DFS path -> cycle
            else if (path[neighbor]) {
                return true;
            }
        }

        // Remove from current recursion path
        path[node] = 0;

        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        // Directed graph: only u -> v
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> visited(V, 0);
        vector<int> path(V, 0);

        // Handle disconnected graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path))
                    return true;
            }
        }

        return false;
    }
};