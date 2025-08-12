class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                if(k==-1) k=nums[i];
                else k=k&nums[i];
            }
        }
        if(k==-1) return 0;
        return k;
    }
};