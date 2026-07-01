class Solution {
  public:
    int solve(vector<int>& height,int ind,vector<int>& dp){
        if(ind==0 ) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int oneStep=solve(height,ind-1,dp)+abs(height[ind]-height[ind-1]);
        int twoStep=INT_MAX;
        if(ind>1) twoStep=solve(height,ind-2,dp)+abs(height[ind]-height[ind-2]);
        return dp[ind]=min(oneStep,twoStep);
    }
    int minCost(vector<int>& height) {
        vector<int>dp(height.size(),-1);
        
        return solve(height,height.size()-1,dp);
        
    }
};