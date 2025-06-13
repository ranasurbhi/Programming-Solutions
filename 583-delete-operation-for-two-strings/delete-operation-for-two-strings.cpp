class Solution {
    int lcs(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // return helper(text1, n-1, text2, m-1,dp);
        for(int indx1=1;indx1<=n;indx1++){
            for(int indx2=1;indx2<=m;indx2++){
                if(s1[indx1-1]==s2[indx2-1]){
                    dp[indx1][indx2]=1+dp[indx1-1][indx2-1];
                }
                else{
                    dp[indx1][indx2]=max(dp[indx1-1][indx2],dp[indx1][indx2-1]);
                }
            }
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return (n+m)-2*lcs(word1,word2);
    }
};