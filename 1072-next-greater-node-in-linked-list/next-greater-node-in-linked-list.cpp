class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        for (auto p = head; p != nullptr; p = p->next) {
            values.push_back(p->val);
        }

        int n = values.size();
        vector<int> ans(n, 0); 
        stack<int> st; 

        for (int i = 0; i < n; i++) {
            while (!st.empty() && values[i] > values[st.top()]) {
                ans[st.top()] = values[i]; 
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
