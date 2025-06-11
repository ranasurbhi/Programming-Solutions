class Solution {
    int helper(int i, int j1, int j2, int r , int c, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
            return -1;
        }

        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }

        if(i==r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];

        }
        
        int maxi=-1;
        for (int k1=-1; k1<=1;k1++){
            for (int k2=-1; k2<=1 ; k2++){
                int value=0;
                if(j1==j2){
                    value=grid[i][j1] + helper(i+1,j1+k1,j2+k2,r,c,grid,dp);
                }
                else{
                    value=grid[i][j1]+grid[i][j2] + helper(i+1,j1+k1,j2+k2,r,c,grid,dp);
                }
                maxi=max(maxi,value);
            }
            
        }
        return dp[i][j1][j2]=maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        return helper(0,0,c-1,r,c,grid,dp);
    }
};