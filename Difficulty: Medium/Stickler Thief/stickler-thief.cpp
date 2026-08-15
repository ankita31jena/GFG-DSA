class Solution {
    public:
      int findMaxSum(vector<int>& arr) {

          int prev2 = 0;  // dp[i-2]
          int prev1 = 0;  // dp[i-1]

          for (int i = 0; i < arr.size(); i++) {

              int take = arr[i] + prev2;
              int notTake = prev1;

              int curr = max(take, notTake);

              prev2 = prev1;
              prev1 = curr;
          }

          return prev1;
      }
  };