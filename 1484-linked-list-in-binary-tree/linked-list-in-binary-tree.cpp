class Solution {
    
    unordered_map<long long, bool> dp;

    long long getKey(ListNode* list, TreeNode* node) {
        return ((long long)list << 32) ^ (long long)node;
    }

    bool helper(ListNode* head, ListNode* temp, TreeNode* root, TreeNode* start, TreeNode* second){
        if(!temp) return true;
        if(!root) return false;

        long long key = getKey(temp, root);
        if(dp.count(key)) return dp[key];  

        bool ans = false;
        if(start){
            if(root->val==temp->val){
                if(!second && root->val==head->val){
                    second=root;
                }
                ans = helper(head,temp->next,root->left,start,second) 
                   || helper(head,temp->next,root->right,start,second);
            }
            else{
                if(!second && root->val==head->val){
                    second=root;
                }
                if(second){
                    ans = helper(head,head->next,second->left,nullptr,nullptr) 
                       || helper(head,head->next,second->right,nullptr,nullptr);
                }
                else{
                    ans = helper(head,head,root->left,nullptr,second) 
                       || helper(head,head,root->right,nullptr,second);
                }
            }
        } 
        else{
            if(root->val==temp->val){
                ans = helper(head,temp->next,root->left,root,nullptr) 
                   || helper(head,temp->next,root->right,root,nullptr);
            }
            else{
                ans = helper(head,head,root->left,nullptr,nullptr) 
                   || helper(head,head,root->right,nullptr,nullptr);
            }
        }

        return dp[key] = ans;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return helper(head,head,root,nullptr,nullptr);
    }
};
