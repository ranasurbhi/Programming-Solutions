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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j:graph[i]){
                // adj[j].push_back(i);
                edges.push_back({j,i});
            }
        }

        
        vector<int> ans=topoSort(n,edges);
        sort(ans.begin(),ans.end());
        return ans;
        // return {};
    }
};