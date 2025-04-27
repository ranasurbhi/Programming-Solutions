class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        summ=0
        for i in range(len(nums)-2):
            if (nums[i]+nums[i+2])==(nums[i+1]/2):
                summ+=1
        return summ