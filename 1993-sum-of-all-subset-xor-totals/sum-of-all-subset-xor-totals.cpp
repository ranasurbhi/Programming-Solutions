class Solution {
    int helper(vector<int>& nums,int i,int n,int total){
        if(i>=n) return total;

        int take=helper(nums,i+1,n,total ^ nums[i]);
        int nottake=helper(nums,i+1,n,total);
        return take+nottake;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        return helper(nums,0,n,0);
    }
};