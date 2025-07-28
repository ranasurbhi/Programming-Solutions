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
    int helper(TreeNode* root, map<TreeNode*,int>& dp){
        if(!root) return 0;

        if(dp[root]!=-1) return dp[root];
        // take
        int take=root->val;
        if(root->left) take+=helper(root->left->left,dp)+helper(root->left->right,dp);
        if(root->right) take+=helper(root->right->left,dp)+helper(root->right->right,dp);
        // nottake
        int nottake=helper(root->left,dp)+helper(root->right,dp);
        return dp[root]=max(take,nottake);
    }
    void dfs(TreeNode* root,map<TreeNode*,int> &dp){
        if(!root) return ;
        dp[root]=-1;
        dfs(root->left,dp);
        dfs(root->right,dp);
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode*,int> dp;
        dfs(root,dp);
        return helper(root,dp);
    }
};