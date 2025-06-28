class Solution {
    bool helper(vector<int>&nums, int n,int summ, int target, vector<vector<int>> &dp){
        if(n<0) return false;

        if(dp[n][summ]!=-1) return dp[n][summ];
        if(summ==target) return true;
        // take
        bool take=helper(nums,n-1,summ+nums[n],target,dp);
        // nottake
        bool notTake=helper(nums,n-1,summ,target,dp);
        return dp[n][summ]=(take || notTake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int summ=0;
        int n=nums.size();
        for(int it:nums){
            summ+=it;
        }
        if(summ%2!=0) return false;
        vector<vector<int>> dp(n,vector<int> ((summ)+1,-1));
        return helper(nums,n-1,0,summ/2,dp);
    }
};