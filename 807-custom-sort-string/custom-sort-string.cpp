class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        multiset<char> st;
        for(char it:s){
            st.insert(it);
        }
        // set bn gaya s ka
        for(char it:order){
            if(st.count(it)==0) continue;
            int size=st.count(it);
            while(size--){
                ans+=it;
                
            }
            st.erase(it);
        }
        if(st.size()==0) return ans;
        for(char it:st){
            ans+=it;
        }
        return ans;
    }
};