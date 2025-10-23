class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                int sz=st.size();
                ans=max(ans,sz);
                st.pop();
            }
            
        }
        return ans;
    }
};