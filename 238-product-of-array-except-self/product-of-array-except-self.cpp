class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1;
        int r=1;
        int n=nums.size();
        vector<int> ans(n,1);
        for(int i=0;i<nums.size();i++){
            ans[i]*=l;
            ans[n-i-1]*=r;
            l*=nums[i];
            r*=nums[n-i-1];
        }
        return ans;
    }
};