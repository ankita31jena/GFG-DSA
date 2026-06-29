class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>vis(adj.size(),0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int node=q.front();
            bfs.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};