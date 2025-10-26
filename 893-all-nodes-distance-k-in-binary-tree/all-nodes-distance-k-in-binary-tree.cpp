/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void prepAdj(TreeNode* root,map<int,vector<int>>& adj){
        if(!root) return;
        if(root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            prepAdj(root->left,adj);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            prepAdj(root->right,adj);
        }
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,vector<int>> adj;
        prepAdj(root,adj);

        queue<int>q;
        q.push(target->val);
        vector<int> ans;
        unordered_set<int> s;
        s.insert(target->val);

        while(k>0 && !q.empty()){
            k--;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int temp=q.front();
                q.pop();
                for(int ele:adj[temp]){
                    if(s.count(ele)==0){
                        s.insert(ele);
                        q.push(ele);
                        
                    }
                }
            }
            
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};