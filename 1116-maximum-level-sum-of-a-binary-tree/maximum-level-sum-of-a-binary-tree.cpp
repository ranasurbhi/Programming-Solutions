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
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum=-1e8;
        int level=-1;
        queue<TreeNode*> q;
        q.push(root);
        int clevel=0;
        while(!q.empty()){
            clevel++;
            int qSize=q.size();
            int sum=0;
            for(int i=0;i<qSize;i++){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(maxSum<sum){
                maxSum=sum;
                level=clevel;
            }
            
        }
        return level;
    }
};