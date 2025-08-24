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
    ListNode* insertionSortList(ListNode* head) {
        map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        ListNode* c=head;
        ListNode* temp=dummy;
        while(c){
            ListNode* curr=c;
            c=c->next;
            temp=dummy;
            while(temp->next && temp->next->val < curr->val){
                temp=temp->next;
            }
            if(!temp->next) {
                temp->next=curr;
                curr->next=nullptr;
            }
            else {
                curr->next=temp->next;
                temp->next=curr;
            }
            // curr=curr->next;
        }
        return dummy->next;
    }
};