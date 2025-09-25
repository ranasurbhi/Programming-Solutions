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
        if(!root) return nullptr;
        bool flag=false;
        // lh
        if(!helper(root->left)) {
            root->left=nullptr;
        }
        else flag=true;
        // rh
        if(!helper(root->right)){
            root->right=nullptr;
        }
        else flag=true;
        if(flag || root->val==1) return root;

        return nullptr;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return helper(root);
    }
};