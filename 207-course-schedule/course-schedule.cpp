class Solution {
    bool dfs(vector<vector<int>> &adj, set<int> &st, vector<int> &vis,int &i){
        vis[i]=1;
        st.insert(i);
        int s=adj[i].size();
        bool res=false;
        for(int j=0;j<s;j++){
            if(!vis[adj[i][j]]){
                res=res || dfs(adj,st,vis,adj[i][j]);
            }
            else if(st.count(adj[i][j])){
                return true;
            }
        }
        // vis[i]=0;
        st.erase(i);
        return res;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // graph 
        vector<vector<int>> adj(numCourses);
        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses,0);
        
        // cycle detect
        bool res=false;
        set<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                res=res || dfs(adj,st,vis,i);
                // vis[i]=1;
            }

        }
        return !res;
    }
};