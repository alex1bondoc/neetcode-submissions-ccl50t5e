class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        leftMax, rightMax = 0, 0
        res = 0
        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax, height[left + 1])
                res += leftMax - height[left]
            else:
                right -= 1
                rightMax = max(leftMax, height[right + 1])
                res += leftMax - height[right]
        return res