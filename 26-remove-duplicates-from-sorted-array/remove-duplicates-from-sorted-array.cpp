class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for (auto it=nums.begin()+1;it!=nums.end();it++){
            if (nums[i]!= *it){
                nums[i+1]=*it;
                i++;
            }
        }
        return i+1;
    }
};