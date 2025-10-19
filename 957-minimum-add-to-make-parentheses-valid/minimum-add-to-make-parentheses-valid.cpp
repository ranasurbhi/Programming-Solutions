class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int closingOnes=0;
        for(char it:s){
            if(it=='('){
                st.push(it);
            }
            else{
                if(!st.empty()) st.pop();
                else closingOnes++;
            }
        }
        return st.size()+closingOnes;
    }
};