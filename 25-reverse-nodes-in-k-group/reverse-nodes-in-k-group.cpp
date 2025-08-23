class Solution {
    ListNode* reverse(ListNode* root1,ListNode* root2){
        ListNode* curr=root1;
        ListNode* prev=nullptr;
        while(prev!=root2){
            ListNode* next=curr->next;

            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* root1=head;
        ListNode* root2=head;
        ListNode* temp=dummy;
        while(root1 && root2){
            // cout<<root1->val<<"="<<root2->val<<endl;
            for(int i=1;i<k;i++){
                if(root2) root2=root2->next;
            }

            if(root2){
                // cout<<root1->val<<"="<<root2->val<<endl;
                ListNode* n=root2->next;
                temp->next=reverse(root1,root2);
                // cout<<temp->next->val<<endl;
                temp=root1;
                // cout<<temp->val<<endl;
                root1=n;
                root2=root1;
            }

        }
        if(root1){
            temp->next=root1;
            root1=root1->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
