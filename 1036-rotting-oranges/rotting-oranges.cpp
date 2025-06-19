class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int rotten=0;
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    rotten++;
                }
            }
        }
        if(rotten==0) return 0;
        
        while(!q.empty()){
            int s=q.size();
            for(int ind=0;ind<s;ind++){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                // up i-1 j
                if(i-1>=0 && grid[i-1][j]==1){
                    q.push({i-1,j});
                    grid[i-1][j]=2;
                    rotten--;
                }
                // down i+1 j
                if(i+1<n && grid[i+1][j]==1){
                    q.push({i+1,j});
                    grid[i+1][j]=2;
                    rotten--;
                }
                // left i j-1
                if(j-1>=0 && grid[i][j-1]==1){
                    q.push({i,j-1});
                    grid[i][j-1]=2;
                    rotten--;
                }
                // right i j+1
                if(j+1<m && grid[i][j+1]==1){
                    q.push({i,j+1});
                    grid[i][j+1]=2;
                    rotten--;
                }

            }
            count++;
        }
        if(rotten!=0){
            return -1;
        }
        return count-1;
    }
};