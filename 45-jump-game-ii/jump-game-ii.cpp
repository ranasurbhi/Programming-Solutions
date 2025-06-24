class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size()-1;
        int jump=0, currEnd=0, currfar=0-1;
        for(int i=0;i<n;i++){
            currfar=max(currfar, i+nums[i]);
            if(currEnd==i){
                jump++;
                currEnd=currfar;
            }
        }
        return jump;  
    }
};
