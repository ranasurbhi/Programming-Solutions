class Solution {
    int timer=1;
    void helper(int node,int par,vector<vector<int>> &adj,vector<int>&vis, vector<vector<int>>& ans,vector<int>& tin,vector<int>& low){
        vis[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                helper(it,node,adj,vis,ans,tin,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);

            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n),ans;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> vis(n,0);
        vector<int> tin(n);
        vector<int> low(n);
        helper(0,-1,adj,vis,ans,tin,low);
        return ans;
    }
};