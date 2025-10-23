class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        // map<int ,set<char>>fmp;
        vector<set<char>>fmp(s.size()+1);
        for(auto it:mp){
            
            fmp[it.second].insert(it.first);
        }
        reverse(fmp.begin(),fmp.end());

        int t=fmp.size()-1;
        string res="";
        for(auto it:fmp){
            for(char c:it){
                int i=t;
                while(i>0){
                    res+=c;
                    i--;
                }
            } 
            t--;    
        }
        return res;
    }
};