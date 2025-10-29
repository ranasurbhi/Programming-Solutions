class NumberContainers {
    unordered_map<int,int> indi;
    unordered_map<int,set<int>> vali;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indi.count(index)==0){
            indi[index]=number;
            vali[number].insert(index);
        }
        else{
            int val=indi[index];
            vali[val].erase(index);
            indi[index]=number;
            vali[number].insert(index);
            if(vali[val].empty()) vali.erase(val);
        }
    }
    
    int find(int number) {
        if(vali.count(number)){
            return *vali[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */