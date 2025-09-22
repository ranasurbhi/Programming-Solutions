class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());

        map<int,long> dp;
        int mod=1e9 + 7;
        int ans=0;
        for(int i=0;i<n;i++){
            dp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    dp[arr[i]]=(dp[arr[i]]+(dp[arr[i]/arr[j]])*dp[arr[j]])%mod;
                }
            }
            ans=(ans+dp[arr[i]])%mod;
        }
        return ans;
    }
};