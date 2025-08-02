class Solution {
    void helper(int n,int k,vector<int> &temp,vector<vector<int>> &ans,int i){
        if(i>n) return;
        if(k==0){
            ans.push_back(temp);
            return;
        }
        // take
        temp.push_back(i);
        helper(n,k-1,temp,ans,i+1);
        temp.pop_back();
        // nottake
        helper(n,k,temp,ans,i+1);

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(n+1,k,temp,ans,1);
        return ans;
    }
};