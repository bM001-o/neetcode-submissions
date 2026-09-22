class Solution:
    def minWindow(self, s: str, t: str) -> str:
        countT = {}
        for c in t:
            countT[c] = 1 + countT.get(c,0)
        
        left,right = 0,0
        resL,res = float("infinity"),[-1,-1]
        formed,required = 0,len(countT) 

        window = {}
        while right < len(s):
            c = s[right]
            window[c] = 1 + window.get(c,0)

            if c in countT and window[c] == countT[c]:
                formed += 1

            while formed == required:
                if(right - left + 1 < resL):
                    resL = right - left + 1
                    res = [left,right]
                
                window[s[left]] -= 1
                
                if s[left] in countT and window[s[left]] < countT[s[left]]:
                    formed -= 1
                left += 1

            right += 1
        
        l,r = res
        return s[l : r + 1] if resL != float("infinity") else ""  