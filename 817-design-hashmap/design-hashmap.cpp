struct Node{
int key=-1;
int val;
Node* left;
Node* right;
public:
    Node(int keyv,int value){
        key=keyv;
        val=value;
        left=nullptr;
        right=nullptr;
        return;
    }
};
class MyHashMap {
Node* head;
public:
    MyHashMap() {
        head=new Node(-1,-1);
    }
    
    void put(int key, int value) {
        Node* temp=head;
        Node* nn=new Node(key,value);
        while(temp){
            if(temp->key > key){
                // left jana chahiye
                if(!temp->left){
                    temp->left=nn;
                    return;
                }
                else{
                    temp=temp->left;
                }
            }
            else if(temp->key < key){
                // right jana
                if(!temp->right){
                    temp->right=nn;
                    return;
                }
                else{
                    temp=temp->right;
                }
            }
            else{
                temp->val=value;
                return;
            }
        }
        
    }
    
    int get(int key) {
        Node* temp=head;
        while(temp){
            if(temp->key > key){
                // left jana chahiye
                if(!temp->left){
                    return -1;
                }
                else{
                    temp=temp->left;
                }
            }
            else if(temp->key < key){
                // right jana
                if(!temp->right){
                    return -1;
                }
                else{
                    temp=temp->right;
                }
            }
            else{
                return temp->val;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        Node* temp=head;
        
        while(temp){
            if(temp->key > key){
                // left jana chahiye
                if(!temp->left){
                    return ;
                }
                else{
                    temp=temp->left;
                }
            }
            else if(temp->key < key){
                // right jana
                if(!temp->right){
                    return ;
                }
                else{
                    temp=temp->right;
                }
            }
            else{
                temp->val=-1;
                return ;
            }
        }
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */