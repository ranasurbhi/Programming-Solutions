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
    void helper(TreeNode* root, int targetSum, vector<vector<int>>&ans, vector<int> temp){
        if(!root) return;
        targetSum-=root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && targetSum==0) {
            ans.push_back(temp);
            return;
        }
        helper(root->left,targetSum,ans,temp);
        helper(root->right,targetSum,ans,temp);
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        helper(root,targetSum,ans,{});
        return ans;
    }
};