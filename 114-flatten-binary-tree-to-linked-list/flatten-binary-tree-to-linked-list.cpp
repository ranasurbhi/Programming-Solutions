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
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* l=helper(root->left);
        TreeNode* r=helper(root->right);
        if(l){
            TreeNode* temp=l;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=r;
            root->left=NULL;
            root->right=l;
        }
        
        
        
        return root;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
        return ;
    }
};