class Solution {
    bool isPalindrome(string &s, int i, int j){
        if(i>=j) return true;

        if(s[i]==s[j]){
            return isPalindrome(s,i+1,j-1);
        }

        return false;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=0;
        int st=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j) && maxLen<(j-i+1)){
                    maxLen=(j-i+1);
                    st=i;
                }
            }
        }
        return s.substr(st,maxLen);
    }
};