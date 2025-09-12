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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;

        }
        int rem=n%k;
        int len=n/k;
        vector<ListNode*> ans(k,nullptr);
        temp=head;
        // if(rem) len+=1;
        for(int i=0;i<k;i++){
            ans[i]=temp;
            ListNode* prev=temp;
            for(int j=0;j<(len);j++){
                prev=temp;
                if(temp) temp=temp->next;
            }
            if(rem) {
                rem--;
                prev=temp;
                if(temp) temp=temp->next;
            }
            if(prev) prev->next=nullptr;
        }
        return ans;
    }
};