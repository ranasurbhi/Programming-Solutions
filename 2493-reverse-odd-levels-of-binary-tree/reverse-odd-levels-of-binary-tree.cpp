/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        int n=0;
        while(!q.empty()){
            queue<TreeNode*> l;
            stack<int> st;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                l.push(temp);
                st.push(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(n%2!=0){
                while(!l.empty() && !st.empty()){
                    TreeNode* temp=l.front();
                    l.pop();
                    int v=st.top();
                    st.pop();
                    temp->val=v;
                }
            }
            n++;
        }
        return root;
    }
};