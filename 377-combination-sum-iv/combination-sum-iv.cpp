class Solution {
    vector<int> dp;
    
    int helper(vector<int>& nums, int target) {
        if (target == 0) return 1;  
        if (target < 0) return 0;   

        if (dp[target] != -1) return dp[target];

        int res = 0;
        for (int num : nums) {
            if (target >= num) {
                res += helper(nums, target - num);
            }
        }

        return dp[target] = res;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);  
        return helper(nums, target);
    }
};
