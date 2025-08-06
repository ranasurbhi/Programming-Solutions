class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> s;

        ListNode* temp = headA;
        while (temp) {
            s.insert(temp);
            temp = temp->next;
        }

        
        temp = headB;
        while (temp) {
            if (s.count(temp)) {
                return temp; 
            }
            temp = temp->next;
        }

        return nullptr; 
    }
};
