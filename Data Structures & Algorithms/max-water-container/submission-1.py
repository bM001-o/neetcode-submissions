class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left, right = 0, len(heights) - 1
        maxArea = float("-infinity")

        while left <= right:
            maxArea = max(maxArea,min(heights[left],heights[right]) * (right - left))
            if heights[left] > heights[right]:
                right -= 1
            else:
                left += 1

        return maxArea    
        
