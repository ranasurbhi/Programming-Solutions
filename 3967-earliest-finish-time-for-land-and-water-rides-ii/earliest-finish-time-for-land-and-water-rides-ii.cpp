class Solution {
    public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return (a.first + a.second) < (b.first + b.second);
    }
    int helper(vector<pair<int, int>> vec, int minutes){
        int result = INT_MAX;
        int left = 0, right = vec.size() - 1;
        for(int i = 0; i < vec.size(); i++){
            int start = max(vec[i].first, minutes);
            int dur = start + vec[i].second;
            result = min(result, dur);
        }
        return result;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        vector<pair<int, int>> land, water;
        for(int i = 0; i < n; i++){
            land.push_back({landStartTime[i], landDuration[i]});
        }
        for(int i = 0; i < m; i++){
            water.push_back({waterStartTime[i], waterDuration[i]});
        }
        sort(land.begin(), land.end(), cmp);
        sort(water.begin(), water.end(), cmp);
        //When Land is chosen first
        int minutes1 = land[0].first + land[0].second;
        int time1 = helper(water, minutes1);
        //When Water is chosen first
        int minutes2 = water[0].first + water[0].second;
        int time2 = helper(land, minutes2);
        return min(time1, time2);
    }
};