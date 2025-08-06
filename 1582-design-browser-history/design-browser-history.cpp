class Node{
public:
    string val;
    Node* next;
    Node* prev;

    Node(string x) {
        val = x;
        next = nullptr;
        prev = nullptr;
    }
};
class BrowserHistory {
    Node* temp;
public:
    BrowserHistory(string homepage) {
        temp = new Node(homepage);
    }
    
    void visit(string url) {
        this->temp->next=new Node(url);
        this->temp->next->prev=temp;
        this->temp=this->temp->next;
    }
    
    string back(int steps) {
        while(this->temp->prev && steps){
            this->temp=this->temp->prev;
            steps--;
        }
        // if(this->temp->prev)  
        return this->temp->val;
    }
    
    string forward(int steps) {
        while(this->temp->next && steps){
            this->temp=this->temp->next;
            steps--;
        }
        // if(this->temp->next)  
        return this->temp->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */