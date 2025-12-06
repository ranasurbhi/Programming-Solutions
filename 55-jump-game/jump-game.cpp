class Solution {
    bool helper(vector<int>& nums,int i,vector<int> &dp, int n){
        if(i>=n) return false;
        if(i==n-1) return true;

        if(dp[i]!=-1) return dp[i];
        bool res=false;     
        for(int j=1;j<=min(n,nums[i]);j++){
            res=res || helper(nums,i+j,dp,n);
        }
        return dp[i]=res;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(nums,0,dp,n);
    }
};