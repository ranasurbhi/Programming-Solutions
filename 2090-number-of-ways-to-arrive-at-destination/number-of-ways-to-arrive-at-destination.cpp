class Solution {
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mode=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<long long> ways(n,0);
        ways[0]=1;
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> q;
        q.push({0,0});

        while(!q.empty()){
            auto [t,u] = q.top();
            q.pop();
            if(t > dis[u]) continue;

            for(auto [v,d]: adj[u]){
                if(dis[v] > d + t){
                    dis[v] = d + t;
                    q.push({dis[v], v});
                    ways[v]=ways[u];
                }
                else if(dis[v] == d + t){
                    ways[v]=(ways[v]+ways[u])%mode;
                }
            }
        }

        return ways[n-1]%mode;
    }
};
