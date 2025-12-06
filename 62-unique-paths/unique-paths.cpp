class Solution {
    int helper(int& m,int& n, int x, int y,vector<vector<int>>& dp){
        if(x==m-1 && y==n-1) return 1;
        if(x<0 || x>=m || y<0 || y>=n) return 0;

        if(dp[x][y]!=-1) return dp[x][y];
        int down=helper(m,n,x+1,y,dp);
        int right=helper(m,n,x,y+1,dp);
        return dp[x][y]=down+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};