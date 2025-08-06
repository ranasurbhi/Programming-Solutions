class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        if(image[sr][sc]==color) return image;
        int same=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                pair<int,int> temp=q.front();
                q.pop();
                int i=temp.first;
                int j=temp.second;
                // i-1 j
                if(i-1>=0 && image[i-1][j]==same){
                    image[i-1][j]=color;
                    q.push({i-1,j});
                }
                // i+1 j
                if(i+1<n && image[i+1][j]==same){
                    image[i+1][j]=color;
                    q.push({i+1,j});
                }
                // i j-1
                if(j-1>=0 && image[i][j-1]==same){
                    image[i][j-1]=color;
                    q.push({i,j-1});
                }
                // i j+1
                if(j+1<m && image[i][j+1]==same){
                    image[i][j+1]=color;
                    q.push({i,j+1});
                }
            }
        }
        return image;
    }
};