class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        Ccount = {}
        maxL = 0
        left = 0
        maxF = 0

        for right in range(len(s)):
            Ccount[s[right]] = 1 + Ccount.get(s[right],0)
            maxF = max(maxF,Ccount[s[right]])

            while right - left + 1 - maxF > k:
                Ccount[s[left]] -= 1
                left += 1

            maxL = max(maxL,right - left + 1)

        return maxL 