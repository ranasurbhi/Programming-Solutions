class Solution {
    int helper(vector<int>& coins, int amount, int i,vector<vector<int>>& dp){
        if(i>=coins.size()){
            if(amount==0) return 0;
            return INT_MAX;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=INT_MAX;
        if(amount>=coins[i]){
            int ans=helper(coins,amount-coins[i],i,dp);

            if(ans!=INT_MAX) take=1+ans;
            
        }
        int nottake=helper(coins,amount,i+1,dp);
        return dp[i][amount]=min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int res=helper(coins,amount,0,dp);
        if(res==INT_MAX) return -1;
        return res;
    }
};