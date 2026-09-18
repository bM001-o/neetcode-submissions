class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        mp_1 = {}
        mp_2 = {}

        for i in range (len(s)):
            mp_1[s[i]] = 1 + mp_1.get(s[i],0)
            mp_2[t[i]] = 1 + mp_2.get(t[i],0)

        if mp_1 == mp_2:
            return True 
        return False