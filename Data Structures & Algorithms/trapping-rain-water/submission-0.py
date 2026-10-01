class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
            return 0
        
        left, right = 0, len(height) - 1
        leftMax, rightMax = height[left], height[right]
        trapped_water = 0

        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax,height[left])
                trapped_water += leftMax - height[left]

            else:
                right -= 1
                rightMax = max(rightMax,height[right])
                trapped_water += rightMax - height[right]

        return trapped_water