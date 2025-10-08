class Solution {
    bool check(vector<int>& nums, int tar, int n){
        int summ=0;
        for(int it:nums){
            summ+=ceil(it/(n*1.0));
        }
        return summ<=tar;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};