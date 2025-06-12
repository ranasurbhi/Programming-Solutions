class Solution {
    int helper(int n, int k,vector<int>& arr ,vector<vector<int>> &dp){
    	if(n==-1){
    		if(k==0){
    			return 1;
    		}
    		else return 0;
    	}
    
    
    	if(dp[n][k]!=-1) return dp[n][k];
    	int inc=0;
    	if(arr[n]<=k){
    		inc=helper(n-1,k-arr[n],arr,dp);
    	}
    	int notinc=helper(n-1,k,arr,dp);
    	return dp[n][k]=inc+notinc;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
	    if ((sum-target)<0||(sum - target) % 2 != 0) return 0;
	   // k=total+d/2
	    int k=(sum - target)/2;
	    
	    vector<vector<int>> dp(n,vector<int>(k+1,-1));
	    return helper(n-1,k,nums,dp);
    }
};