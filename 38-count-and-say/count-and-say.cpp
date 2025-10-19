class Solution {
    string helper(int n){
        if(n==1) return "1";

        string s=helper(n-1);
        string ans="";
        char prev=s[0];
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(prev==s[i]){
                cnt++;
            }
            else{
                ans+=to_string(cnt)+prev;
                prev=s[i];
                cnt=1;
            }
        } 
        ans+=to_string(cnt)+prev;
        return ans;
    }
public:
    string countAndSay(int n) {
        return helper(n);
    }
};