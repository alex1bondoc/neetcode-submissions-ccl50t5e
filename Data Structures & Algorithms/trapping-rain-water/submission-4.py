class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 1, len(height) - 2
        leftMax, rightMax = height[0], height[right + 1]
        res = 0
        while left < right:
            if leftMax < rightMax:
                left += 1
                leftMax = max(leftMax, height[left + 1])
                res += leftMax - height[left]
            else:
                right -= 1
                rightMax = max(leftMax, height[right + 1])
                res += rightMax - height[right]
        return res