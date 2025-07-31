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
    int helper(TreeNode* root,int maxi){
        if(!root) return 0;

        int left=helper(root->left, max(maxi,root->val));
        int right=helper(root->right, max(maxi,root->val));
        if(root->val >=maxi) return 1+left+right;
        return left+right;
    }
public:
    int goodNodes(TreeNode* root) {
        return helper(root,-1e5);
    }
};