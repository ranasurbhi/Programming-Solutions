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
    bool helper(TreeNode* root, int k,set<int>& s){
        if(!root) return false;
        if(s.count(root->val)) return true;
        s.insert(k-root->val);
        return helper(root->left,k,s) || helper(root->right,k,s);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        return helper(root,k,s);
    }
};