class Solution {
    
    double dfs(string src, string dest, 
               map<string, vector<pair<string,double>>> &mp, 
               set<string> &vis)
    {
        if (mp.find(src) == mp.end()) return -1.0;   
        if (src == dest) return 1.0;                
        
        vis.insert(src);

        for (auto &p : mp[src]) {
            string next = p.first;
            double weight = p.second;

            if (!vis.count(next)) {
                double val = dfs(next, dest, mp, vis);
                if (val != -1.0)
                    return val * weight;          
            }
        }

        return -1.0; 
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) 
    {
        map<string, vector<pair<string,double>>> mp;
        
        
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            mp[a].push_back({b, val});
            mp[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        // Solve queries
        for (auto &q : queries) {
            string a = q[0], b = q[1];
            set<string> vis;

            double res = dfs(a, b, mp, vis);
            ans.push_back(res);
        }

        return ans;
    }
};
