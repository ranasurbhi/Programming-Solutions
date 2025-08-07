class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            // i-1 j
            if(i-1>=0 && !vis[i-1][j]){
                vis[i-1][j]=1;
                q.push({i-1,j});
                mat[i-1][j]=1+mat[i][j];
            }
            // i+1 j
            if(i+1<n && !vis[i+1][j]){
                vis[i+1][j]=1;
                q.push({i+1,j});
                mat[i+1][j]=1+mat[i][j];
            }
            // i j-1
            if(j-1>=0 && !vis[i][j-1]){
                vis[i][j-1]=1;
                q.push({i,j-1});
                mat[i][j-1]=1+mat[i][j];
            }
            // i j+1
            if(j+1<m && !vis[i][j+1]){
                vis[i][j+1]=1;
                q.push({i,j+1});
                mat[i][j+1]=1+mat[i][j];
            }
        }
        return mat;
    }
};