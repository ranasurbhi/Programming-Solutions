class Solution {
    int helper(int m, int n, int x, int y, vector<vector<int>> &dp){
        if(x==m-1&& y==n-1){
            return 1;
        }
        if(x>=m || y>=n) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        // right
        int right=helper(m,n,x,y+1,dp);
        // down
        int down=helper(m,n,x+1,y,dp);
        return dp[x][y]=right+down;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(m,n,0,0,dp);
    }
};