class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {

        vector<bool> dp(sum + 1, false);

        dp[0] = true;

        for (int num : arr) {

            // Traverse backwards so each element is used only once
            for (int s = sum; s >= num; s--) {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[sum];
    }
};