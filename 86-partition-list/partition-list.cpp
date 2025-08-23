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
    ListNode* partition(ListNode* head, int x) {
        vector<vector<ListNode*>> part(2);
        ListNode* temp=head;
        while(temp){
            if(temp->val < x){
                part[0].push_back(temp);
            }
            else{
                part[1].push_back(temp);
            }
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(0);
        temp=dummy;
        for(int i=0;i<2;i++){
            for(ListNode* j:part[i]){
                temp->next=j;
                temp=temp->next;
            }
        }
        temp->next=nullptr;
        return dummy->next;
    }
};