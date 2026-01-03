class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0];
        int n=nums.size();
        int p1=1;
        int p2=1;
        while(p1<n && p2<n){
            if(nums[p2]>prev){
                nums[p1]=nums[p2];
                prev=nums[p1];
                p2++;
                p1++;
            }
            else{
                p2++;
            }
        }
        return p1;
    }
};