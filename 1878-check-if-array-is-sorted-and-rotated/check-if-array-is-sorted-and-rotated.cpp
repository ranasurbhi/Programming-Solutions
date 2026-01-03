class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(nums[0]<nums[n-1]){
            // aready sorted 
            for(int i=1;i<n;i++){
                if(nums[i-1]>nums[i]) return false;
            }
            return true;
        }
        else{
            int cnt=0;
            for(int i=1;i<n;i++){
                if(nums[i-1]>nums[i]) cnt++;
            }
            if(cnt>1) return false;
            return true;
        }
    }
};