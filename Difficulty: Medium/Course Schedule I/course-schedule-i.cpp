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

        // Remove from current DFS path
        path[node] = 0;

        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {

        vector<vector<int>> adj(n);

        // pre[i] = {course, prerequisite}
        // prerequisite -> course
        for (auto &p : pre) {
            int course = p[0];
            int prerequisite = p[1];

            adj[prerequisite].push_back(course);
        }

        vector<int> visited(n, 0);
        vector<int> path(n, 0);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                if (dfs(i, adj, visited, path))
                    return false;
            }
        }

        return true;
    }
};