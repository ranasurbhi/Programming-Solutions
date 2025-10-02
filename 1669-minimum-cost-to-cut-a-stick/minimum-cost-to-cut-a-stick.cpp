class Solution {
    int helper(vector<int>&cuts, int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int ans=(cuts[j+1]-cuts[i-1])+helper(cuts,i,k-1,dp)+helper(cuts,k+1,j,dp);
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int s=cuts.size();
        vector<vector<int>> dp(s+1,vector<int>(s+1,-1));
        return helper(cuts,1,s-2,dp);
    }
};