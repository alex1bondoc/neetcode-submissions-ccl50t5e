class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        l, r = 0, 0
        currHeight = 0
        s = 0
        while r < len(height) and l < len(height):
            if height[r] < height[l]:
                s += height[l] - height[r]
                r += 1
            else :
                res += s
                s = 0
                l = r
                r = l + 1
        return res
