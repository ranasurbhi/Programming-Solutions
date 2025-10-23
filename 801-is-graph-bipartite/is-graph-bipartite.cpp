class Solution {
    bool helper(vector<vector<int>>& graph, vector<int>& vis, int i, int color){
        vis[i]=color;
        bool res=true;
        for(int x:graph[i]){
            if(vis[x]==-1){
                res &= helper(graph,vis,x,!color);
            }
            else{
                if(vis[x]==color) return false;
            }
        }
        return res;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        bool res=true;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                res &= helper(graph,vis,i,0);
            }
        }
        return res;
    }
};