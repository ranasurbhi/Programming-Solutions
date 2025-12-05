class Solution {
    unordered_map<long long, int> dp[20005];

    int helper(vector<int>& nums, int i, long long currProd) {
        if (i >= nums.size()) return currProd;

        if (dp[i].count(currProd)) return dp[i][currProd];

        long long currVal = (currProd == LLONG_MIN ? nums[i] : currProd * nums[i]);

        int ntake = helper(nums, i + 1, LLONG_MIN);
        int take = helper(nums, i + 1, currVal);

        return dp[i][currProd] = max((long long)currVal, max((long long)ntake, (long long)take));
    }

public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return helper(nums, 0, LLONG_MIN);
    }
};
