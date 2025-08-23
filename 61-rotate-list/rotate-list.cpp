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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=0;
        while(slow){
            cnt++;
            slow=slow->next;
        }
        slow=head;
        k%=cnt;
        for(int i=0;i<k;i++){
            if(fast) fast=fast->next;
        }
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next;

            
        }
        if(fast){
            fast->next=head;
            head=slow->next;
            slow->next=nullptr;
        }
        return head;
    }
};