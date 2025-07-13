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
    void helper(TreeNode* root, int mini, int maxi,int &maxDiff){
        if(mini>root->val) mini=root->val;
        else if(maxi<root->val) maxi=root->val;
        
        if(!root->left && !root->right){
            maxDiff=max(maxDiff,(maxi-mini));
            return;
        }
        if(root->left) helper(root->left,mini,maxi,maxDiff);
        if(root->right) helper(root->right,mini,maxi,maxDiff);


    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff=0;
        if(!root) return maxDiff;
        helper(root,root->val,root->val,maxDiff);
        return maxDiff;
    }
};