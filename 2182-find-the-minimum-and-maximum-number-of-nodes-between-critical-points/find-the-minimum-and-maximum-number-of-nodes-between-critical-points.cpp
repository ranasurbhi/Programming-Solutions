/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        if(!head) return {-1,-1};
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* third=nullptr;
        if(head->next) third=head->next->next;
        else return {-1,-1};
        int count=3;
        while(third){
            // cout<<first->val<<" "<<second->val<<" "<<third->val<<" ";
            if((second->val > first->val && second->val > third->val) || (second->val < first->val && second->val < third->val)){
                ans.push_back(count);
                // cout<<"aaya kuch to";
            }
            first=first->next;
            second=second->next;
            third=third->next;
            count++;
        }
        int n=ans.size();
        int mini=INT_MAX;
        
        for(int i=0;i<n-1;i++){
            // cout<<ans[i]<<" ";
            mini=min(mini,ans[i+1]-ans[i]);
        }
        if(n-1>0) cout<<ans[n-1]<<" ";
        if(n<=1) return{-1,-1};
        return {mini,ans[n-1]-ans[0]};
    }
};