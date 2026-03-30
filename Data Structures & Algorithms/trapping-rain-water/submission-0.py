class Solution:
    def trap(self, height: List[int]) -> int:
        prefix = [0] * len(height)
        sufix = [0] * len(height)
        x = height[0]
        for i in range(len(height)):
            if i == 0:
                prefix[i] = x
                continue
            prefix[i] = max(height[i], prefix[i - 1])
        x = height[len(height) - 1]
        for i in range(len(height) - 1, -1, -1):
            if i == len(height)-1:
                sufix[i] = x
                continue
            sufix[i]= max(height[i], sufix[i + 1])
        maxi = 0
        for i in range(len(height)):
            maxi += max(0,min(prefix[i], sufix[i]) - height[i])
        return maxi