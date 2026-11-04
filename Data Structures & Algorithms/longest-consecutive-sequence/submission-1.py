class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(sorted(nums))
        maxCount = 0

        for x in s:
            if x - 1 not in s:
                curr = x
                count = 1

                while curr + 1 in s:
                    count += 1
                    curr += 1

                maxCount = max(count,maxCount)

        return maxCount 