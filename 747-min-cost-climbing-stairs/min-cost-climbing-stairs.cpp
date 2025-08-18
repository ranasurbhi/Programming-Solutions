class Solution {
    int helper(vector<int> &cost, int i, int n,vector<int> &dp){
        if(i>=n) return 0;

        if(dp[i]!=-1) return dp[i];
        // take 1
        int one=cost[i]+helper(cost,i+1,n,dp);
        // take 2
        int two=cost[i]+helper(cost,i+2,n,dp);
        return dp[i]=min(one,two);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(helper(cost,0,n,dp),helper(cost,1,n,dp));
    }
};