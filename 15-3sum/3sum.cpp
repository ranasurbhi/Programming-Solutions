class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end()); // IMPORTANT
        set<vector<int>> ans;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i-1>0 && nums[i]==nums[i-1]) continue;
            unordered_map<int,int> mp;
            int tar = -nums[i];
           
            for(int j = i+1; j < n; j++){
                int need = tar - nums[j];

                if(mp.count(need)){
                    ans.insert({nums[i], need, nums[j]});
                }
                mp[nums[j]] = j;
            }
        }

        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};
