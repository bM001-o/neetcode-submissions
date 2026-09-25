class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [None] * (n + 1)

        for i in range(0,n + 1):
            if i == 0 or i == 1:
                dp[i] = 1
            else:
                dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]