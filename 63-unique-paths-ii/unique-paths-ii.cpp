class Solution {
    int helper(int m, int n, int x, int y, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid){
        if(x==m-1&& y==n-1 && obstacleGrid[x][y]==0){
            return 1;
        }
        if(x>=m || y>=n) return 0;
        if(obstacleGrid[x][y]==1){
            return dp[x][y]=0;
        }
        if(dp[x][y]!=-1) return dp[x][y];
        // right
        int right=helper(m,n,x,y+1,dp,obstacleGrid);
        // down
        int down=helper(m,n,x+1,y,dp, obstacleGrid);
        return dp[x][y]=right+down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(m,n,0,0,dp,obstacleGrid);
    }
};