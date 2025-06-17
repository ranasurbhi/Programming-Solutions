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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        if(!root) return ans;
        bool flag=false;
        while(!q.empty()){
            int s=q.size();
            vector<int> l;
            for (int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                l.push_back(temp->val);
            }
            if(flag){
                reverse(l.begin(),l.end());
                flag=false;
            }
            else{
                flag=true;
            }
            ans.push_back(l);
        }
        return ans;
    }
};