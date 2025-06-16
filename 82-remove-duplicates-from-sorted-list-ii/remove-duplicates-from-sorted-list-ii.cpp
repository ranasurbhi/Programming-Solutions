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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;

        ListNode dummy(0);  // Added dummy node
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            bool isDuplicate = false;
            ListNode* next = curr->next;

            while (next && curr->val == next->val) {
                isDuplicate = true;
                next = next->next;
            }

            if (isDuplicate) {
                prev->next = next;  
            } else {
                prev = curr;       
            }

            curr = next;  
        }

        return dummy.next;
    }
};
