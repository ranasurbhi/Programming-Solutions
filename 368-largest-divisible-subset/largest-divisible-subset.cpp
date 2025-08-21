class Solution {
    int helper(vector<int>& nums, int i, int last, vector<vector<int>>& dp, vector<vector<int>>& parent) {
        if(i >= nums.size()) return 0;

        if(dp[i][last+1] != -1) return dp[i][last+1];

        // not take
        int notTake = helper(nums, i+1, last, dp, parent);

        // take
        int take = 0;
        if(last == -1 || nums[i] % nums[last] == 0) {
            take = 1 + helper(nums, i+1, i, dp, parent);
            if(take >= notTake) {
                parent[i][last+1] = 1; 
            }
        }

        if(notTake > take) {
            parent[i][last+1] = 0; 
        }

        return dp[i][last+1] = max(take, notTake);
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        vector<vector<int>> parent(n, vector<int>(n+1, -1));

        int maxLen = helper(nums, 0, -1, dp, parent);

        // reconstruct answer
        vector<int> ans;
        int i = 0, last = -1;
        while(i < n) {
            if(parent[i][last+1] == 1) { 
                ans.push_back(nums[i]);
                last = i;
            }
            i++;
        }
        return ans;
    }
};
