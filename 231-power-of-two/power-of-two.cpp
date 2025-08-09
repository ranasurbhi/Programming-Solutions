class Solution {
    bool helper(double n){
        if(n==1) return true;
        if(n==2) return true;
        if(n<2) return false;

        double m=n/2;
        return helper(m);
    }
public:
    bool isPowerOfTwo(int n) {
        return helper(n);
    }
};