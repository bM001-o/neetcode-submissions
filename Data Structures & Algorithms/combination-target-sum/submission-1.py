class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        idx = 0

        def findCombinationSum(idx,cur,target):
            if idx == len(nums):
                if target == 0:
                    res.append(cur.copy())
                
                return
        
            if nums[idx] <= target:
                cur.append(nums[idx])
                findCombinationSum(idx,cur,target - nums[idx])
                cur.pop()
        
            findCombinationSum(idx + 1,cur,target)
        
        findCombinationSum(0,[],target)
        return res

