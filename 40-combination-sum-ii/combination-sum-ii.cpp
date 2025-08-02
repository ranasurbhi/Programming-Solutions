class Solution {
    void helper(vector<int>& candidates, int target, int i, int n,vector<int> temp, vector<vector<int>>&ans,int summ,int currSum){
        if(summ==target){
            ans.push_back(temp);
            return;
        }
        
        if(i>=n){
            return;
        }
        if(currSum>target) return;
        // take
        
        temp.push_back(candidates[i]);
        helper(candidates,target,i+1,n,temp,ans,summ+candidates[i],currSum+candidates[i]);
        temp.pop_back();
        // nottake
        int j=i;
        while(j<n && candidates[j]==candidates[i]){
            j++;
        }

        helper(candidates,target,j,n,temp,ans,summ,currSum);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        helper(candidates,target,0,n,{},ans,0,0);
        return ans;
    }
};