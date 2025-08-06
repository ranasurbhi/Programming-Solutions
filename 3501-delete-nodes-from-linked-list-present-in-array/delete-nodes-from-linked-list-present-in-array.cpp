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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* curr=head;
        while(curr){
            if(numSet.count(curr->val)){
                curr=curr->next;
            }
            else{
                temp->next=curr;
                temp=temp->next;
                curr=curr->next;
            }
        }
        temp->next=nullptr;
        return dummy->next;
    }
};