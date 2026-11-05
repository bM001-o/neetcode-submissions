class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxprofit = 0
        Min = 100

        for i in range(0,len(prices)):
            Min = min(prices[i],Min)
            maxprofit = max(prices[i] - Min,maxprofit)
        
        return maxprofit