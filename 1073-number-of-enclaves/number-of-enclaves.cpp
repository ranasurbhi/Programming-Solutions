class Solution {
    void dfs(vector<vector<int>>& vis, int x, int y){
        vis[x][y]=0;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};

        int n=vis.size();
        int m=vis[0].size();

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>0 && nx<n && ny>0 && ny<m && vis[nx][ny]==1){
                dfs(vis,nx,ny);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis;
        vis=grid;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            if(vis[0][i]==1) dfs(vis,0,i);
            if(vis[n-1][i]==1) dfs(vis,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(vis[i][0]==1) dfs(vis,i,0);
            if(vis[i][m-1]==1) dfs(vis,i,m-1);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==1) ans++;
            }
        }
        return ans;
    }
};