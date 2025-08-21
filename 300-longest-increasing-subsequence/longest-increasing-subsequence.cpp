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
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        for(int i=n-1;i>=0;i--){
            for(int last=i-1;last>=-1;last--){
                int nottake=dp[i+1][last+1];

                int take=0;
                if(last==-1 || nums[i]>nums[last]){
                    take= 1 + dp[i+1][i+1];
                }
                dp[i][last+1]=max(take,nottake);
            }
        }
        // return helper(nums,0,n,-1,dp);
        return dp[0][0];
    }
};