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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=head->next;
        while(temp!=NULL){
            curr->next=prev;

            prev=curr;
            curr=temp;
            temp=temp->next;
        }
        curr->next=prev;
        return curr;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        int maxSum=INT_MIN;
        ListNode* mid=reverseList(slow);
        fast=head;
        while(fast!=NULL && fast->next!=NULL){
            int sum=mid->val + fast->val;
            maxSum=max(maxSum,sum);
            mid=mid->next;
            fast=fast->next;
        }
        return maxSum;
    }
};