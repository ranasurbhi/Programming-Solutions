class Solution {
    int helper(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        int first=helper(n-1,dp);
        int second=helper(n-2,dp);
        return dp[n]=first+second;
    }
public:
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};