class Solution {
    int helper(vector<vector<int>>& matrix, int n, int m, int x, int y,vector<vector<int>> &dp){
        if(x==n) return 0;

        if(dp[x][y]!=INT_MAX){
            return dp[x][y];
        }
        // r+1 c-1
        int same=INT_MAX, pdiag=INT_MAX, ndiag=INT_MAX;
        if(y-1>=0){
            pdiag=helper(matrix,n,m,x+1,y-1,dp);
        }
        // r+1 c
        same=helper(matrix,n,m,x+1,y,dp);
        // r+1 c+1
        if(y+1<m){
            ndiag=helper(matrix,n,m,x+1,y+1,dp);
        }
        return dp[x][y] = matrix[x][y] + min({pdiag, same, ndiag});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int minele=INT_MAX;
        vector<vector<int>> dp(n,vector<int> (m,INT_MAX));
        for(int i=0;i<m;i++){
            minele=min(minele,helper(matrix,n,m,0,i,dp));
        }
        return minele;
    }
};