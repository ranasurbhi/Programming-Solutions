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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* temp=second;
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(temp){
            while(temp->val!=0){
                temp=temp->next;
            }
            second=temp;
            temp=first->next;
            int summ=0;
            while(temp!=second){
                summ+=temp->val;
                temp=temp->next;
            }
            // first->next->val=summ;
            // first->next->next=second;
            curr->next=new ListNode(summ);
            curr=curr->next;
            temp=second->next;
            first=second;
        }
        return dummy->next;
    }
};