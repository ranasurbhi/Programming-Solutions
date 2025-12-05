class Solution {
    int helper(string& text1, string& text2, int i, int j,vector<vector<int>>& dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        int same=0;
        if(text1[i]==text2[j]) {
            same=1+helper(text1,text2,i+1,j+1,dp);
        }
        
        int notSame=max(helper(text1,text2,i+1,j,dp),helper(text1,text2,i,j+1,dp));

        return dp[i][j]=max(same,notSame);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1,text2,0,0,dp);
    }
};