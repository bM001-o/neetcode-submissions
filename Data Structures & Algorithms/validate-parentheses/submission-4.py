class Solution:
    def isValid(self, s: str) -> bool:
        stk = []

        for c in s:
            if c == "(" or c == "{" or c == "[":
                stk.append(c)
            
            else:
                if len(stk) == 0:
                    return False
                elif c == ")" and stk[-1] == "(":
                    stk.pop()
                elif c == "}" and stk[-1] == "{":
                    stk.pop()
                elif c == "]" and stk[-1] == "[":
                    stk.pop()
                else:
                    stk.append(c)
            
        return True if len(stk) == 0 else False