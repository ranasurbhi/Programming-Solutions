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
    void sumOfNodes(TreeNode* root,int &sum,int tempSum){
        if(!root) return;
        if(!root->left && !root->right){
            tempSum=(tempSum*10) + root->val;
            sum+=tempSum;
            return;
        }
        tempSum=(tempSum*10) + root->val;
        sumOfNodes(root->left,sum,tempSum);
        sumOfNodes(root->right,sum,tempSum);
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        sumOfNodes(root,sum,0);
        return sum;
    }
};