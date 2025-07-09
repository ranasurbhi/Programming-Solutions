class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e7);
        dis[src] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dis; 
            for (int u = 0; u < n; u++) {
                for (auto& [v, cost] : adj[u]) {
                    if (dis[u] != 1e7 && temp[v] > dis[u] + cost) {
                        temp[v] = dis[u] + cost;
                    }
                }
            }
            dis = temp;
        }

        return dis[dst] == 1e7 ? -1 : dis[dst];
    }
};
