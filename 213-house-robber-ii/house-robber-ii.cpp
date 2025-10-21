class Solution {
    int helper(vector<int>& nums,int i,vector<vector<int>>& dp, int lastRobbed){
        if(i<0) return 0;
        
        if(dp[i][lastRobbed]!=-1) return dp[i][lastRobbed];
        int take=0, nottake=0;
        if(i==0){
            if(lastRobbed) {
                return 0;
            }
            else{
                return nums[i];
            }

        }
        else if(i==nums.size()-1){
            take=helper(nums,i-2,dp,1)+nums[i];
            nottake=helper(nums,i-1,dp,0);
        }
        else{
            take=helper(nums,i-2,dp,lastRobbed)+nums[i];
            nottake=helper(nums,i-1,dp,lastRobbed);
        }
        
        return dp[i][lastRobbed]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return helper(nums,n-1,dp,0);
    }
};