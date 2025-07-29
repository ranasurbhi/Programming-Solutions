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
    TreeNode* helper(TreeNode* root,int i){
        if(!root) {
            TreeNode* node=new TreeNode(i);
            return node;
        }
        if(root->val<i){
            root->right=helper(root->right,i);
        }
        else if(root->val>i){
            root->left=helper(root->left,i);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if(n==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<n;i++){
            helper(root,preorder[i]);
        }
        return root;
    }
};