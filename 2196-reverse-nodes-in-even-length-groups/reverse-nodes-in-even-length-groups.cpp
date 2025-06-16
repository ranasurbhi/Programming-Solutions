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
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != tail) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev; 
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        int groupSize = 1;

        while (curr) {
            ListNode* groupStart = curr;
            int count = 0;

            
            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            if (count % 2 == 0) {
                
                ListNode* reversed = reverseList(groupStart, curr);
                prev->next = reversed;

                groupStart->next = curr;
                prev = groupStart;
            } else {
                prev = groupStart;
                for (int i = 1; i < count; i++) {
                    prev = prev->next;
                }
            }

            groupSize++;
        }

        return dummy->next;
    }
};
