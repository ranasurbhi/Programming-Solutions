class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        int i=0;
        while(i<s.size()){
            if(s[i]!=' '){
                string temp="";
                while(i<s.size() && s[i]!=' '){
                    temp+=s[i];
                    i++;
                }
                words.push_back(temp);
                
            }
            i++;
        }
        reverse(words.begin(),words.end());
        string res="";
        for(string i:words){
            res+=(i+' ');
        }
        if(res.size()>0) res.pop_back();
        return res;
    }
};