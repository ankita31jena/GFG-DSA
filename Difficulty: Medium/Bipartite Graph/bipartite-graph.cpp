class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        // Convert edge list to adjacency list
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);

        for (int start = 0; start < V; start++) {
            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};