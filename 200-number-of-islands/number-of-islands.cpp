class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int numI=0;
        vector<vector<int>> v(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!v[i][j] && grid[i][j]=='1'){
                    numI++;
                    v[i][j]=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int sz=q.size();
                        for(int k=0;k<sz;k++){
                            pair<int,int>temp=q.front();
                            q.pop();
                            int f=temp.first;
                            int s=temp.second;
                            // top i-1 j
                            if(f-1>=0 && v[f-1][s]==0 && grid[f-1][s]=='1'){
                                v[f-1][s]=1;
                                q.push({f-1,s});
                            }
                            // bottom i+1 j
                            if(f+1<n && v[f+1][s]==0 && grid[f+1][s]=='1'){
                                v[f+1][s]=1;
                                q.push({f+1,s});
                            }
                            // left i j-1
                            if(s-1>=0 && v[f][s-1]==0 && grid[f][s-1]=='1'){
                                v[f][s-1]=1;
                                q.push({f,s-1});
                            }

                            // right i j+1
                            if(s+1<m && v[f][s+1]==0 && grid[f][s+1]=='1'){
                                v[f][s+1]=1;
                                q.push({f,s+1});
                            }
                        }
                    }
                }
            }
        }
        return numI;
    }
};