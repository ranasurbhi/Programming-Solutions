class Solution {
    int helper(int n,int indx,vector<int> &dp){
        if(indx>n){
            return 0;
        }
        if(indx==n){
            return 1;
        }
        if(dp[indx]!=-1){
            return dp[indx];
        }

        int one=helper(n,indx+1,dp);
        int two=helper(n,indx+2,dp);
        return dp[indx]=one+two;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n,-1);
        return helper(n,0,dp);
    }
};