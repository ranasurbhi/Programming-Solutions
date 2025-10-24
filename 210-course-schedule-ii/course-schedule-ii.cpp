class Solution {
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> indegree(V,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]+=1;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> ans;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i:adj[temp]){
                indegree[i]-=1;
                if(indegree[i]==0) q.push(i);
            }
            
        }
        return ans;
    }
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> ans=topoSort(V,edges);
        reverse(ans.begin(),ans.end());
        if(ans.size()!=V) return {};
        return ans;
    }
};