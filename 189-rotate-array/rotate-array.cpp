class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        int f1=n-k;
        reverse(nums.begin(),nums.begin()+f1);
        reverse(nums.begin()+f1,nums.end());
        reverse(nums.begin(),nums.end());
    }
};