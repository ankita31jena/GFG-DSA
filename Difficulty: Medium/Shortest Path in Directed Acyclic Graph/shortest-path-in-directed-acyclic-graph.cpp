class Solution {
  public:

    void topoSort(int node, vector<vector<pair<int,int>>> &adj,
                  vector<int> &vis, stack<int> &st) {

        vis[node] = 1;

        for (auto it : adj[node]) {
            int neighbor = it.first;

            if (!vis[neighbor]) {
                topoSort(neighbor, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>> adj(V);

        // Build directed weighted graph
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // Topological sort
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        // Distance from source 0
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // Only process reachable nodes
            if (dist[node] != INT_MAX) {

                for (auto it : adj[node]) {
                    int neighbor = it.first;
                    int wt = it.second;

                    if (dist[node] + wt < dist[neighbor]) {
                        dist[neighbor] = dist[node] + wt;
                    }
                }
            }
        }

        // Unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};