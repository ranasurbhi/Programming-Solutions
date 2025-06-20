class Solution {
    int helper(vector<int>& prices,int count, int ind, int buy, int n, vector<vector<vector<int>>> &dp,int k){
        if(count==k) return 0;
        if(ind==n) return 0;

        if(dp[ind][buy][count]!=-1){
            return dp[ind][buy][count];
        }
        int profit=0;
        if(buy==0){
            profit=max(helper(prices,count,ind+1,0,n,dp,k),helper(prices,count,ind+1,1,n,dp,k)-prices[ind]);
        }
        else{
            profit=max(helper(prices, count,ind+1,1,n,dp,k),helper(prices,count+1,ind+1,0,n,dp,k)+prices[ind]);
        }
        return dp[ind][buy][count]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (k,-1)));
        return helper(prices,0,0,0,n,dp,k);
    }
};