class Solution {
  public:
    vector<int>solve(vector<vector<int>> &adj, vector<int> &ans,vector<int> &vis,int node){
        vis[node]=1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(vis[it]==0){
                solve(adj,ans,vis,it);
            }
        }
        return ans;
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>vis(adj.size(),0);
        int start=0;
        vector<int>ans;
        return solve(adj,ans,vis,start);
    }
};