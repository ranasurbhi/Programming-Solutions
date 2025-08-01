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
    void dfs(TreeNode* root,vector<int> &ans){
        if(!root) return;

        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        int n=ans.size();
        for(int i=1;i<n;i++){
            if(ans[i]<=ans[i-1]) return false;

        }
        return true;
    }
};