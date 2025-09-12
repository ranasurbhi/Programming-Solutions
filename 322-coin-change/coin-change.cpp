class Solution {
    int helper(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (amount == 0) return 0;    
        if (i < 0) return INT_MAX;   

        if (dp[i][amount] != -1) return dp[i][amount];

        int take = INT_MAX;
        if (amount >= coins[i]) {
            int subproblem = helper(coins, amount - coins[i], i, dp);
            if (subproblem != INT_MAX)
                take = 1 + subproblem;  
        }

        // Do not take current coin
        int nottake = helper(coins, amount, i - 1, dp);

        return dp[i][amount] = min(take, nottake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int res = helper(coins, amount, n - 1, dp);

        return (res == INT_MAX) ? -1 : res;
    }
};
