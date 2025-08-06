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
    ListNode* rev(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;

            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        ListNode* root1=nullptr;
        ListNode* root2=nullptr;
        ListNode* temp=head;
        int s=0;
        while(temp){
            temp=temp->next;
            s++;
        }
        temp=head;
        // cout<<s;
        while(temp){
            if(count==k-1){
                root1=temp;
                // temp=temp->next;
            }
            else if(count==((s-k)%s)){
                root2=temp;
            }
            
            temp=temp->next;
            
            count++;
        }
        if(root1 && root2) {
            int val=root1->val;
            root1->val=root2->val;
            root2->val=val;
        }
        return head;
    }
};