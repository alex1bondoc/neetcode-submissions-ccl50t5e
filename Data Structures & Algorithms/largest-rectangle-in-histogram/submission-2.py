class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)
        stack = []
        maxArea = 0

        for i in range(n):
            mini = heights[i]
            while stack and heights[stack[-1]] < heights[i]:
                mini = min(mini, heights[stack[-1]])
                stack.pop()
            if stack:
                maxArea = max(maxArea, mini * (i - stack[-1] + 1))
            maxArea = max(maxArea, mini)
            maxArea = max(maxArea, heights[i])
            stack.append(i)
            print(stack)
        return maxArea