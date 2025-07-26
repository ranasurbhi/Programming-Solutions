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
    void check(TreeNode* root,int l ,int level, map<int,map<int,vector<int>>> & ans){
        if(!root) return ;
        ans[level][l].push_back(root->val);
        check(root->left,l+1,level-1,ans);
        check(root->right,l+1,level+1,ans);
        return;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        map<int,map<int,vector<int>>> ans;
        check(root,0,0,ans);

        for(auto it:ans){
            // res.push_back(it.second);
            vector<int> temp;
            for(auto i:it.second){
                vector<int> t=i.second;
                sort(t.begin(),t.end());
                for( int j:t){
                    temp.push_back(j);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};