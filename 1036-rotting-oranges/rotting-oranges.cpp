class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOrange=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) freshOrange++;
                else if(grid[i][j]==2){
                    q.push({i,j});
                    v[i][j]=1;
                }
            }
        }

        if(!freshOrange) return 0;
        int time=0;
        while(!q.empty()){
            int sz = q.size();
            for (int t = 0; t < sz; t++) {
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                // top i-1 j
                if(i-1>=0 && v[i-1][j]==0 && grid[i-1][j]==1){
                    v[i-1][j]=1;
                    q.push({i-1,j});
                    freshOrange--;
                }
                // bottom i+1 j
                if(i+1<n && v[i+1][j]==0 && grid[i+1][j]==1){
                    v[i+1][j]=1;
                    q.push({i+1,j});
                    freshOrange--;
                }
                // left i j-1
                if(j-1>=0 && v[i][j-1]==0 && grid[i][j-1]==1){
                    v[i][j-1]=1;
                    q.push({i,j-1});
                    freshOrange--;
                }
                // right i j+1
                if(j+1<m && v[i][j+1]==0 && grid[i][j+1]==1){
                    v[i][j+1]=1;
                    q.push({i,j+1});
                    freshOrange--;
                }
            }
            time++;
        }

        if(freshOrange) return -1;
        return time-1;
        
    }
};