class Solution {
    int helper(int x, int y, vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
        
        if(x<0 || y<0 || obstacleGrid[x][y]==1) return 0;
        if(x==0 && y==0) return 1;

        if(dp[x][y]!=-1) return dp[x][y];
        int up=helper(x-1,y,dp,obstacleGrid);
        int left=helper(x,y-1,dp,obstacleGrid);
        return dp[x][y]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp,obstacleGrid);
    }
};