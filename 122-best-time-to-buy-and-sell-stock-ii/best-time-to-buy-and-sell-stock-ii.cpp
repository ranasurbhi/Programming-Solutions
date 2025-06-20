class Solution {
    int helper(vector<int>& prices,int ind,int buy,int n,vector<vector<int>> &dp){
        if(ind==n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==0){
            profit=max(helper(prices,ind+1,0,n,dp),helper(prices,ind+1,1,n,dp)-prices[ind]);
        }
        else{
            profit=max(helper(prices,ind+1,1,n,dp),helper(prices,ind+1,0,n,dp)+prices[ind]);
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return helper(prices,0,0,n,dp);
    
    }
};