class Solution {
    bool dfs(int n,vector<int>&v,vector<int>  &recStack,vector<vector<int>> &adj,int i){
        v[i]=1;
        recStack[i]=1;
        for(int it:adj[i]){
            if(recStack[it]){
                return true;
            }
            else if(!v[it] && dfs(n,v,recStack,adj,it)){
                return true;
            }
        }
        recStack[i]=0;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& preReq) {
        vector<int> v(n,0);
        vector<int>  recStack(n,0);
        vector<vector<int>> adj(n);
        for(auto it:preReq){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(v[i]==0 && dfs(n,v,recStack,adj,i)){
                return false;
            }
        }
        return true;
    }
};