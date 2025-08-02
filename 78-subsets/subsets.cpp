class Solution {
    void helper(vector<int>&nums,vector<int> temp,vector<vector<int>>&ans,int i,int n){
        if(i>=n){
            ans.push_back(temp);
            return ;
        }
        // take
        temp.push_back(nums[i]);
        helper(nums,temp,ans,i+1,n);
        temp.pop_back();
        // nottake
        helper(nums,temp,ans,i+1,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        helper(nums,{},ans,0,n);
        return ans;
    }
};