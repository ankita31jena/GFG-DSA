
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<vector<int>> adj(V);

        // Undirected graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, -1);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return dist[node];

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        return -1;
    }
};