class Solution {
    void dfs(int i, vector<vector<int>> &adj, vector<int>&vis){
        vis[i]=1;

        for(int it:adj[i]){
            if(!vis[it]) dfs(it,adj,vis);
        }
        return;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;

        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);

        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cout<<i<<" ";
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};