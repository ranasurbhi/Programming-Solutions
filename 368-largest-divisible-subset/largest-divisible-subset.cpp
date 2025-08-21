class Solution {
    int helper(vector<int>& nums, int i, int n, int last,vector<vector<int>> &dp, vector<vector<int>> &parent){
        if(i>=n) return 0;

        if(dp[i][last+1]!=-1) return dp[i][last+1];
        // nottake
        int nottake=helper(nums,i+1,n,last,dp,parent);
        // take
        int take=0;
        if(last==-1 || nums[i]%nums[last]==0){
            take=1+helper(nums,i+1,n,i,dp,parent);
            if(take>=nottake){
                parent[i][last+1]=1;
            }
        }

        if(take<nottake) {
            parent[i][last+1]=0;
        }
        return dp[i][last+1]=max(take,nottake);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        vector<vector<int>> parent(n,vector<int>(n+1,-1));
        int res=helper(nums,0,n,-1,dp,parent);
        // for(auto it:parent){
        //     for(int i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<n;i++){
        //     if(parent[n-1][i]!=-1) ans.push_back(nums[i]);
        // }
        int i=0, last=-1;
        while(i<n){
            if(parent[i][last+1]==1){
                ans.push_back(nums[i]);
                last=i;
            }
            i++;
        }
        return ans;
    }
};