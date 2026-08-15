class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> prev(3);

        // Day 0
        prev[0] = mat[0][0];
        prev[1] = mat[0][1];
        prev[2] = mat[0][2];

        for (int day = 1; day < n; day++) {

            vector<int> curr(3);

            // Choose activity 0
            curr[0] = mat[day][0] + max(prev[1], prev[2]);

            // Choose activity 1
            curr[1] = mat[day][1] + max(prev[0], prev[2]);

            // Choose activity 2
            curr[2] = mat[day][2] + max(prev[0], prev[1]);

            prev = curr;
        }

        return max({prev[0], prev[1], prev[2]});
    }
};