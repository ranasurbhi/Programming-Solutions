class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int start=0, end=0;
        int n=s.size();
        int cnt=-1;
        while(end<n){
            if(s[start]==s[end]){
                cnt++;
            }

            else {
                cnt=0;
                start=end;
                }

            if(cnt<2){
                ans+=s[end];
            }
            end++;
        }
        return ans;
    }
};