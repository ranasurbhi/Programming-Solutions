class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=nums.size()-2;
        int p=nums.size()-1;
        while(i>=0){
            if(p-i<=nums[i]){
                p=i;
            }
            i--;
        }
        return p==0;
    }
};