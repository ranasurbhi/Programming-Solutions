class Solution {
    int helper(int target, vector<int>&nums){
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                // if(mid-1>0 && nums[mid-1]!=target) return 
                // l=mid;
                r=mid;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return r;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> temp;
        int first=helper(target,nums);
        int second=helper(target+1,nums);
        if(second>=0 && second<n && nums[second]!=target) second-=1;
        if(n==1) second=first;

        if(first>=0 && first<n && nums[first]==target) temp.push_back(first);
        else temp.push_back(-1);
        if(second>=0 && second<n && nums[second]==target) temp.push_back(second);
        else temp.push_back(-1);
        return temp;
    }
};