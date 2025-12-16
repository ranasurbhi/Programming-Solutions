struct cmp{
    int operator()(pair<int,int> a,pair<int,int>b){
        if(a.second>b.second){
            return 0;
        }
        return 1;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int num:nums) m[num]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        for(auto it:m){
            pq.push({it.first,it.second});
        }
        vector<int> ans;
        for(int i=1;i<=k;i++){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};