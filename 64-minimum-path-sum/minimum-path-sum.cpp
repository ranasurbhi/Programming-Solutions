class Solution {
    int helper(vector<vector<int>>& grid,int x, int y,vector<vector<int>>&dp){
        if(x==0 && y==0) return grid[x][y];
        if(x<0 || y<0 ) return INT_MAX;
        if(dp[x][y]!=-1) return dp[x][y];

        int up=helper(grid,x-1,y,dp);
        int left=helper(grid,x,y-1,dp);
        return dp[x][y]=grid[x][y]+min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};