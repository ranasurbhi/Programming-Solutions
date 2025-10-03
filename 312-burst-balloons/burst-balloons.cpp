class Solution {
public:
    int maxCoins(vector<int>& cuts) {
        cuts.insert(cuts.begin(),1);
        cuts.push_back(1);
        int s=cuts.size();
        vector<vector<int>> dp(s+2,vector<int>(s+2,0));

        for(int i=s-2;i>=1;i--){
            for(int j=i;j<=s-2;j++){
                // if(dp[i][j]!=-1) return dp[i][j];
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int ans=(cuts[j+1]*cuts[i-1]*cuts[k])+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,ans);
                }
                dp[i][j]=maxi;
            }
        }

        return dp[1][s-2];
    }
};