class Solution {
    void dfs(vector<vector<int>>& rooms, vector<int>& vis, int i){
        vis[i]=1;
        for(int it:rooms[i]){
            if(!vis[it]){
                dfs(rooms,vis,it);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        dfs(rooms,vis,0);

        for(int it:vis){
            if(it==0) return false;
        }
        return true;
    }
};