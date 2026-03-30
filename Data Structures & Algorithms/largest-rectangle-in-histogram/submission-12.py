class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        res = 0
        for i in range(len(heights)):
            while stack and heights[i] <= heights[stack[-1]]:
                h = heights[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                res = max(res, h * w) 
            stack.append(i)

        
        while stack:
            h = heights[stack.pop()]
            w = len(heights) if not stack else i - stack[-1]
            res = max(res, h * w) 
        return res