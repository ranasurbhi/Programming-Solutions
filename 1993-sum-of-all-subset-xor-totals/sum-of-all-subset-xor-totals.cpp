class Solution {
    void helper(vector<int>& nums,int i,int n,vector<int> temp,int &summ){
        if(i>=n) {
            int res=0;
            for(int it:temp){
                res=res ^ it;
            }
            summ+=res;
            return ;
        }
        temp.push_back(nums[i]);
        helper(nums,i+1,n,temp,summ);
        temp.pop_back();
        helper(nums,i+1,n,temp,summ);
        return ;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int summ=0;
        helper(nums,0,n,{},summ);
        return summ;
    }
};