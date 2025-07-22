/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node* temp=head;
        while(temp){
            if(!temp->child){
                if (temp->next) {
                    temp=temp->next;
                    }
                else if(!st.empty()){
                    Node* dummy=st.top();
                    st.pop();
                    temp->next=dummy;
                    dummy->prev=temp;
                    temp=temp->next;
                }
                else{
                    break;
                }
            }
            else if(temp->child){
                if(temp->next) st.push(temp->next);
                temp->next=temp->child;
                temp->child->prev=temp;
                temp->child=NULL;
                temp=temp->next;
            }
            

        }
        
        
        return head;
    }
};