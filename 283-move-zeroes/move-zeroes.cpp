class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        
        while(i<nums.size()){
            while(j<nums.size() && nums[j]!=0){
                j++;
            }
            i=j+1;
            while(i<nums.size() && nums[i]==0){
                i++;
            }
            if(i<nums.size() && j<nums.size() && nums[i]!=0 && nums[j]==0){
                swap(nums[i],nums[j]);
            }
            i++;
        }
    }
};