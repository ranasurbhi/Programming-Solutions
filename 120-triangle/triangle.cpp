class Solution {
    int helper(vector<vector<int>>& tri, int x, int y, int n, vector<vector<int>>& dp){
        if(x==n-1 ) return tri[x][y];
        // if(x>=n ) return INT_MAX;
        if(dp[x][y]!=-1) return dp[x][y];

        int down=helper(tri, x+1, y,n, dp);
        int rightDown=helper(tri, x+1,y+1,n, dp);
        return dp[x][y]=tri[x][y]+min(down,rightDown);
    }
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++) dp[n-1][i]=tri[n-1][i];

        for(int x=n-2;x>=0;x--){
            for(int y=x;y>=0;y--){
                int down=dp[x+1][y];
                int rightDown=dp[x+1][y+1];
                dp[x][y]=tri[x][y]+min(down,rightDown);
            }
        }
        return dp[0][0];
    }
};