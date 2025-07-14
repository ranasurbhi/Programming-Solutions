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
    void traversal(TreeNode* root, int &summ){
        if(!root) return;
        if(root->left){
            if(!root->left->left && !root->left->right){
                summ+=root->left->val;
            }
            else{
                traversal(root->left,summ);
            }
        }
        if(root->right) traversal(root->right,summ);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int summ=0;
        traversal(root,summ);
        return summ;
    }
};