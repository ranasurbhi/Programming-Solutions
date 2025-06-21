class Solution {
    void dfs(int i,vector<vector<int>> adj, vector<int> &vis){
        vis[i]=1;

        for(int j=0;j<adj[i].size();j++){
            if(!vis[adj[i][j]])
                dfs(adj[i][j],adj,vis);
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt=0;
        // adjlist
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n,0);
        // vis[0]=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};