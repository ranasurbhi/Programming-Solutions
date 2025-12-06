class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        // int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(nums[mid]>=nums[l]){
                // left sorted
                if(nums[mid]==target) return mid;
                if(nums[mid]>target && nums[l]<=target){
                    int templ=l;
                    int tempr=mid-1;
                    while(templ<=tempr){
                        int m=(templ+tempr)/2;
                        if(nums[m]==target) return m;
                        else if(nums[m]<target) templ=m+1;
                        else tempr=m-1;
                    }
                    return -1;
                }
                else l=mid+1;
            }
            else{
                // right sorted
                if(nums[mid]==target) return mid;
                if(nums[mid]<target && nums[r]>=target){
                    int templ=mid+1;
                    int tempr=r;
                    while(templ<=tempr){
                        int m=(templ+tempr)/2;
                        if(nums[m]==target) return m;
                        else if(nums[m]<target) templ=m+1;
                        else tempr=m-1;
                    }
                    return -1;
                }
                else r=mid-1;
            }
        }
        return -1;
    }
};