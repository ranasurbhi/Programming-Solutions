class Solution {
public:
    bool checkValidString(string s) {
        int maxOpen=0;
        int minOpen=0;
        for(int it:s){
            if(it=='('){
                maxOpen++;
                minOpen++;
            }
            else if(it==')'){
                maxOpen--;
                minOpen=max(0,minOpen-1);
            }
            else{
                maxOpen++;
                minOpen=max(0,minOpen-1);
            }
            if (maxOpen<0) return false;
        }
        return minOpen==0;
    }
};