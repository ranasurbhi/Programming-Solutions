class Solution {
    int helper(vector<vector<int>>& triangle, int x, int y, vector<vector<int>>& dp){
        if(x==triangle.size()){
            return 0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        // y
        int noChange=triangle[x][y]+helper(triangle,x+1,y,dp);
        // y+1
        int change=triangle[x][y]+helper(triangle,x+1,y+1,dp);
        return dp[x][y]=min(change,noChange);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return helper(triangle,0,0,dp);
    }
};