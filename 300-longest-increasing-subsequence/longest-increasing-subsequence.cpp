class Solution {
    int helper(vector<int>& nums, int i, int lelement, vector<vector<int>>& dp) {
        int n = nums.size();
        if (i >= n) return 0;                       // return 0 (length from here)
        if (dp[i][lelement + 1] != -1) return dp[i][lelement + 1];

        int take = 0;
        if (lelement == -1 || nums[lelement] < nums[i]) {
            take = 1 + helper(nums, i + 1, i, dp);  // include nums[i] -> +1
        }
        int ntake = helper(nums, i + 1, lelement, dp); // skip nums[i]

        return dp[i][lelement + 1] = max(take, ntake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp[i][prevIndex+1]
        return helper(nums, 0, -1, dp);
    }
};
