class Solution {
public:

    bool dfs(vector<int> adjLs[], vector<int>& vis, int node, int parent) {
        vis[node] = 1;

        for (auto it : adjLs[node]) {
            if (vis[it] == 0) {
                if (dfs(adjLs, vis, it, node))
                    return true;
            }
            else if (it != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adjLs[V];

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adjLs[u].push_back(v);
            adjLs[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (dfs(adjLs, vis, i, -1))
                    return true;
            }
        }

        return false;
    }
};