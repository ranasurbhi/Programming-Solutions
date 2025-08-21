class Solution {
    int helper(vector<int> &nums, int i, int n, int last,vector<vector<int>> &dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][last+1]!=-1) return dp[i][last+1];
        // take
        int take=0;
        if(last==-1 || nums[i]>nums[last]){
            take= 1 + helper(nums,i+1,n,i,dp);
        }
        // nottake
        int nottake=helper(nums,i+1,n,last,dp);
        return dp[i][last+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return helper(nums,0,n,-1,dp);
    }
};