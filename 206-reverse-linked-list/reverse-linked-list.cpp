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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head->next;
        while(temp!=NULL){
            curr->next=prev;


            // traversal
            prev=curr;
            curr=temp;
            temp=temp->next;
        }
        curr->next=prev;
        return curr;
    }
};