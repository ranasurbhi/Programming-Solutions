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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int s=q.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            ans.push_back(temp);
        }
        for(auto it:ans){
            res.push_back(it.back());
        }
        return res;
    }
};