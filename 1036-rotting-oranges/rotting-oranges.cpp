class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(fresh==0) return 0;
        int count=0;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                // i-1 j
                if(i-1>=0 && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                    fresh--;
                }
                // i j+1
                if(j+1<m && grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                    fresh--;
                }
                // i+1 j
                if(i+1<n && grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                    fresh--;

                }
                // i j-1
                if(j-1>=0 && grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                    fresh--;
                }
            }
            count++;
        }
        if(fresh!=0) return -1;
        return count-1;
        
    }
};