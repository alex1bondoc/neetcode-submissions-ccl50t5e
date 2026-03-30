class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max = -1
        i = 0
        j = len(heights) - 1
        while i < j:
            area = (j - i) * min(heights[i], heights[j])
            if area > max:
                max = area
            if heights[i] < heights[j]:
                i += 1
            else:
                j -= 1
    
        return max
        