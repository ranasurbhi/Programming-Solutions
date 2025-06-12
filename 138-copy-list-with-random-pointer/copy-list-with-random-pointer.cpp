/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // next node ka next
        // temp ka update to new node 
        // then traverse next next

        // creating linked copy
        if (head == NULL) return NULL;


        Node* temp=head;
        while(temp!=NULL){
            Node* nn=new Node(temp->val);
            nn->next=temp->next;
            temp->next=nn;
            temp=temp->next->next;

        }
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL){
                temp->next->random=temp->random->next;
            }
            
            temp=temp->next->next;
        }
        
        // deleting the links to seperate them
        Node* curr=head;
        temp=curr->next;
        Node* newHead=temp;
        while(curr!=NULL){
            curr->next=temp->next;
            curr=temp->next;
            if(curr != NULL){
                temp->next = curr->next;
                temp = curr->next;
            } else {
                temp = NULL;
            }
        }
        return newHead;
    }
};