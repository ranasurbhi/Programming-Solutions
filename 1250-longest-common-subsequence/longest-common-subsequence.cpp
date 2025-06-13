class Solution {
    int helper(string &s1,int indx1, string &s2, int indx2,vector<vector<int>> &dp){
        if(indx1<0 || indx2<0){
            return 0;
        }
        

        if(dp[indx1][indx2]!=-1) return dp[indx1][indx2];
        if(s1[indx1]==s2[indx2]){
            return dp[indx1][indx2]=1+helper(s1,indx1-1,s2,indx2-1,dp);

        }
        else{
            return dp[indx1][indx2]=max(helper(s1,indx1-1,s2,indx2,dp),helper(s1,indx1,s2,indx2-1,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(text1, n-1, text2, m-1,dp);
    }
};