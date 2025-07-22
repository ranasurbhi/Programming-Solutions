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
    void traversal(TreeNode* root, int& count){
        if(!root){
            return;
        }
        count++;
        traversal(root->left,count);
        traversal(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        int count=0;
        traversal(root,count);
        return count;
    }
};