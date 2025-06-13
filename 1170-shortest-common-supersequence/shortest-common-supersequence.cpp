class Solution {
    vector<vector<int>> lcs(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return helper(text1, n-1, text2, m-1,dp);
        for (int indx1 = 1; indx1 <= n; indx1++) {
            for (int indx2 = 1; indx2 <= m; indx2++) {
                if (s1[indx1 - 1] == s2[indx2 - 1]) {
                    dp[indx1][indx2] = 1 + dp[indx1 - 1][indx2 - 1];
                } else {
                    dp[indx1][indx2] =
                        max(dp[indx1 - 1][indx2], dp[indx1][indx2 - 1]);
                }
            }
        }
        return dp;
    }
    string findLCS(int n, int m, string& s1, string& s2) {
        // Write your code here.

        vector<vector<int>> dp = lcs(s1, s2);
        int i = n, j = m;
        string ans = "";

        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                ans += s1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        string seq = findLCS(str1.size(), str2.size(), str1, str2);
        int i = 0, j = 0, k = 0;
        string ans = "";
        while (j < str1.size() && k < str2.size() && i < seq.size()) {
            while (i < seq.size() && str1[j] != seq[i]) {
                ans += str1[j++];
            }
            while (i < seq.size() && str2[k] != seq[i]) {
                ans += str2[k++];
            }
            
            ans += seq[i];
            i++;
            j++;
            k++;
        }
        while (j < str1.size()) {
            ans += str1[j];
            j++;
        }
        while (k < str2.size()) {
            ans += str2[k];
            k++;
        }
        return ans;
    }
};