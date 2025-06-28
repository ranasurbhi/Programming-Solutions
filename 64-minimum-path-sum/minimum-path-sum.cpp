class Solution {
    int helper(vector<vector<int>>& grid, int x, int y,int n,int m,vector<vector<int>> &dp){
        if(x==n-1 && y==m-1){
            return grid[x][y];
        }
        if(x>=n || y>=m) return INT_MAX;

        if(dp[x][y]!=-1) return dp[x][y];
        // right
        long long right=helper(grid,x,y+1,n,m,dp);
        // down
        long long down=helper(grid,x+1,y,n,m,dp);
        return dp[x][y]=grid[x][y]+min(right,down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(grid,0,0,n,m,dp);
    }
};