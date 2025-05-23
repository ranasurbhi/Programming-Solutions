class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        for(auto it:nums){
            if (it<0){
                negative.emplace_back(it);
            }
            else{
                positive.emplace_back(it);
            }
        }
        int n=nums.size();
        for (int i=0;i<n;i+=2){
            nums[i]=positive[i/2];
            nums[i+1]=negative[i/2];
        }
        return nums;
    }
};