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
    int minswap(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int> vis(n,0);
        int count=0;
        while(i<n){
            if(vis[i]==1) {
                i++;
                continue;
            }
            int index=i;
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    index++;
                }
            }
            if(index==i){
                vis[i]=1;
                i++;
                continue; 
            }
            else{
                while(nums[i]==nums[index]){
                    index++;
                }
                
                swap(nums[i],nums[index]);
                count++;
            }
        }
        return count;
    }
public:
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode* > q;
        q.push(root);
        // int count=1;
        int ans=0;
        while(!q.empty()){
            int lans=0;
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

                // if(count!=temp->val) lans++;
                // count++;
                level.push_back(temp->val);
            }
            ans+=minswap(level);            
        }
        // if(ans%2!=0) ans=(ans/2)+1;
        // else ans=ans/2;
        // cout<<ans;
        return ans;
    }
};