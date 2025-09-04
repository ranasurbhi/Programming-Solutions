class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0, r=0;
        int n=nums.size();
        while(r<n){
            while(l<n && nums[l]!=0){
                l++;
            }
            r=l+1;
            while(r<n && nums[r]==0){
                r++;
            }
            if(l<n && r<n) swap(nums[l],nums[r]);
            
        }
        
    }
};