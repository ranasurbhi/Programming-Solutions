class Solution {
    int helper(vector<vector<int>>& grid, int x, int i, int j, int n, int m,vector<vector<vector<int>>>& dp){
        if(j<0 || j>=m || i<0 || i>=m) return -1e8;
        
        if(x==n-1) {
            if(i==j) return grid[x][i];
            else return grid[x][i]+grid[x][j];
        }

        if(dp[x][i][j]!=-1) return dp[x][i][j];
        int ans=-1e8;
        for(int k=-1;k<2;k++){
            ans=max(ans,helper(grid,x+1,i-1,j+k,n,m,dp));
            ans=max(ans,helper(grid,x+1,i,j+k,n,m,dp));
            ans=max(ans,helper(grid,x+1,i+1,j+k,n,m,dp));
        }

        if(i==j) ans+=grid[x][i];
        else ans+=grid[x][i]+grid[x][j];
        return dp[x][i][j]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return helper(grid,0,0,m-1,n,m,dp);
    }
};