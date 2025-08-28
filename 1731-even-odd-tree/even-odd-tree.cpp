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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int> l;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                l.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            if(level%2==0){
                int prev=l[0];
                if(prev%2==0) return false;
                for(int i=1;i<l.size();i++){
                    if(prev>=l[i] || l[i]%2==0) return false;
                    prev=l[i];
                }
            }
            else{
                int prev=l[0];
                if(prev%2!=0) return false;
                for(int i=1;i<l.size();i++){
                    if(prev<=l[i] || l[i]%2!=0) return false;
                    prev=l[i];
                }
            }
            // for(int i:l){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            level++;
        }
        return true;
    }
};