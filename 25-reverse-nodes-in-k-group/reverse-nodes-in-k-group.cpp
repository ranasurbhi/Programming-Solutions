class Solution {
    ListNode* reverse(ListNode* root1, ListNode* root2) {
        ListNode* curr = root1;
        ListNode* prev = NULL;
        while (curr != root2) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        ListNode* root1 = head;

        while (root1 != NULL) {
            int temp = 0;
            ListNode* node = root1;

           
            while (temp < k && node) {
                temp++;
                node = node->next;
            }

            if (temp < k) break; 

            ListNode* root2 = node;
            ListNode* newStart = reverse(root1, root2);  

            prevGroupEnd->next = newStart;  
            prevGroupEnd = root1;          
            root1->next = root2;            
            root1 = root2;                  
        }

        return dummy.next;
    }
};
