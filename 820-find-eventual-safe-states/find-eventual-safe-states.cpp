class Solution {
    bool iscycle(vector<vector<int>>& graph, unordered_set<int> &st, int i,vector<int>&dp){
        if(dp[i]!=-1) return dp[i];
        st.insert(i);
        bool res=false;
        
        for(int it:graph[i]){
            if(st.count(it)) return true;
            res=res || iscycle(graph,st,it,dp);
        }
        st.erase(i);
        return dp[i]=res;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        unordered_set<int> st;

        vector<int> dp(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(!iscycle(graph,st,i,dp)) ans.push_back(i);
        }
        return ans;
    }
};