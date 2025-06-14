class Solution {
    int rob2(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            
            int pick=nums[i]; if (i>1) pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);

        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums){
        int n=nums.size();
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if (i==0) 
                temp1.push_back(nums[0]);
            else if(i==n-1){
                temp2.push_back(nums[n-1]);
            }
            else{
                temp1.push_back(nums[i]);
                temp2.push_back(nums[i]);
            }
            
        }
        return max(rob2(temp1),rob2(temp2));
    }
};