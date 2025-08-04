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
    int check(TreeNode* root){
        vector<int> ans;
        dfs(root,ans);
        int n=ans.size();
        for(int i=1;i<n;i++){
            if(ans[i]<=ans[i-1]) return false;

        }
        return true;
    }
    void helper(TreeNode* root, TreeNode* l, TreeNode* r){
        if(!root) return;

        if(l &&  root->val < l->val){
            int temp=root->val;
            root->val=l->val;
            l->val=temp;
            return;
        }
        if(r &&  root->val > r->val){
            int temp=root->val;
            root->val=r->val;
            r->val=temp;
            return;
        }
        helper(root->left,l,root);
        helper(root->right,root,r);
    }
public:
    void recoverTree(TreeNode* root) {
        while(check(root)==false){
            helper(root,nullptr,nullptr);
        }
    }
};