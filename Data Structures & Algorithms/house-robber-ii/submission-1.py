class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)

        def maxSum(left,right):
            currMax = 0
            prevMax = 0
            for i in range(left,right +  1):
                tempMax = max(prevMax,currMax)
                currMax = nums[i] + prevMax
                prevMax = tempMax
            
            return max(prevMax,currMax)
        
        if n == 1:
            return nums[0]
        return max(maxSum(0,n - 2),maxSum(1,n - 1))