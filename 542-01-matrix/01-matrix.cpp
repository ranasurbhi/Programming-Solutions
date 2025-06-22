class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        int level=1;
        while(!q.empty()){
            int s=q.size();
            for(int d=0;d<s;d++){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                if(i-1>=0 && mat[i-1][j]==1 && vis[i-1][j]==0){
                    vis[i-1][j]=1;
                    mat[i-1][j]=level;
                    
                    q.push({i-1,j});
                }
                if(i+1<n && mat[i+1][j]==1 && vis[i+1][j]==0){
                    vis[i+1][j]=1;
                    mat[i+1][j]=level;
                    q.push({i+1,j});
                }
                if(j-1>=0 && mat[i][j-1]==1 && vis[i][j-1]==0){
                    vis[i][j-1]=1;
                    mat[i][j-1]=level;
                    q.push({i,j-1});
                }
                if(j+1<m && mat[i][j+1]==1 && vis[i][j+1]==0){
                    vis[i][j+1]=1;
                    mat[i][j+1]=level;
                    q.push({i,j+1});
                }
            }
            level++;
        }
        return mat;
    }
};