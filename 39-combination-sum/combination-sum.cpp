class Solution {
    void helper(vector<int>& candidates, int target, int i, int n,vector<int> temp,int currSum, vector<vector<int>>&ans){
        if(currSum==target) {
            ans.push_back(temp);
            return;
        }
        if(i>=n) return;

        // take
        if(currSum<target){
            temp.push_back(candidates[i]);
            helper(candidates,target,i,n,temp,currSum+candidates[i],ans);
            temp.pop_back();
        }
        else return;
        // notake
        helper(candidates,target,i+1,n,temp,currSum,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n=candidates.size();
        helper(candidates,target,0,n,{},0,ans);
        return ans;
    }
};