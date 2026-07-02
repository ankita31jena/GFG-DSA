class Solution {
  public:
    void dfs(vector<int> adj[],vector<int> &vis, int node,stack<int> &st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(adj,vis,it,st);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        stack<int>st;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,i,st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};