class Solution {
    vector<int> dp;
    
    bool helper(string& s, vector<string>& wordDict, int x) {
        if (x == s.size()) return true;
        if (dp[x] != -1) return dp[x];
        
        for (string& word : wordDict) {
            int len = word.size();
            if (x + len <= s.size() && s.substr(x, len) == word) {
                if (helper(s, wordDict, x + len)) {
                    return dp[x] = true;
                }
            }
        }
        return dp[x] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);  // Initialize dp array with -1
        return helper(s, wordDict, 0);
    }
};
