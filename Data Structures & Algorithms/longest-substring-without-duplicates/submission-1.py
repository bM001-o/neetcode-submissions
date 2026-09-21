class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxL = 0
        CharSet = set()
        left = 0

        for right in range(len(s)):
            while s[right] in CharSet:
                CharSet.remove(s[left])
                left += 1
            CharSet.add(s[right])
            maxL = max(maxL,right - left + 1)

        return maxL
