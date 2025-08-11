class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> inde(V);
        vector<vector<int>> adj(V);
        for(auto it:edges){
            int u=it[1];
            int v=it[0];
            adj[u].push_back(v);
            inde[v]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inde[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                inde[it]--;
                if(inde[it]==0){
                    q.push(it);
                }
            }
            
            ans.push_back(node);
        }
        if(ans.size()!=V) return {};
        return ans;
    }
};