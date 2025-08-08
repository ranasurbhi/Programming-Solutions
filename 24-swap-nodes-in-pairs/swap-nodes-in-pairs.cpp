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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* dummy=new ListNode(0);
        if(!head) return dummy->next;
        dummy->next=head;
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* prev=dummy;
        while(first && second ){
            first->next=second->next;
            second->next=first;
            prev->next=second;


            prev=first;
            if(first && first->next){
                first=first->next;
                second=first->next;
            }
            else{
                break;
            }
        }
        while(prev->next){
            prev=prev->next;
        }
        return dummy->next;
    }
};