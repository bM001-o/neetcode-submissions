class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [1] * len(nums)

        prefix = 1
        for i in range(0,len(nums)):
            ans[i] = prefix
            prefix = prefix * nums[i]

        suffix = 1
        for j in range(len(nums) - 1,-1,-1):
            ans[j] = ans[j] * suffix
            suffix = suffix * nums[j]
        
        return ans