class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxArea = float("-infinity")
        right = len(heights) - 1
        left = 0

        while left < right:
            currArea = (right - left) * min(heights[right],heights[left])
            maxArea = max(currArea,maxArea)

            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
            
        return maxArea