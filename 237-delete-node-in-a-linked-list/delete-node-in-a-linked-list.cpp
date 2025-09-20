/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        ListNode* next=temp->next;
        while(next && next->next){
            
            temp->val=next->val;
            temp=next;
            next=temp->next;
        }
        temp->val=next->val;
        temp->next=nullptr;
        
    }
};