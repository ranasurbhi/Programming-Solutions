class Solution {
    int helper(vector<vector<int>>& matrix, int x, int y,
               vector<vector<int>>& dp) {
        if (y < 0 || y >= matrix.size())
            return INT_MAX;
        if (x == 0)
            return matrix[x][y];
        if (dp[x][y] != -1)
            return dp[x][y];

        int up = helper(matrix, x - 1, y, dp);
        int topleft = helper(matrix, x - 1, y - 1, dp);
        int topright = helper(matrix, x - 1, y + 1, dp);
        return dp[x][y] = min(topright, min(up, topleft)) + matrix[x][y];
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e8));

        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i];

        for (int x = 1; x < n; x++) {
            for (int y = 0; y < n; y++) {
                
                int up = dp[x - 1][y];
                int topright = (y > 0) ? dp[x - 1][y - 1] : INT_MAX;
                int topleft = (y < n - 1) ? dp[x - 1][y + 1] : INT_MAX;
                dp[x][y] = min(topright, min(up, topleft)) + matrix[x][y];
            }
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};