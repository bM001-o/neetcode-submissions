class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_P = 0
        Min = 101

        for i in range(len(prices)):
            Min = min(Min,prices[i])

            max_P = max(max_P,prices[i] - Min)
        
        return max_P