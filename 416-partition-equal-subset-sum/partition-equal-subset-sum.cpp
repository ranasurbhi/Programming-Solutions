class Solution {
    bool helper(vector<int>& arr, int sum,vector<vector<int>> &dp,int indx){
        if(sum==0) return true;
        if(sum<0 || indx>=arr.size()) return false;
        if(dp[indx][sum]!=-1) return dp[indx][sum];
        
        bool include=helper(arr,sum-arr[indx],dp,indx+1);
        bool notinclude=helper(arr,sum,dp,indx+1);
        
        return dp[indx][sum]=(include || notinclude);
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for (auto it:nums){
            sum += it;
        }

        if((sum & 1 )== 1) return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return helper(nums,sum/2,dp,0);
    }
};