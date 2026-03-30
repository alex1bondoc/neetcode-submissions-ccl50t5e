class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        s = -1
        maxSum = -1001
        for num in nums:
            if s < 0:
                s = 0
            s += num
            maxSum = max(maxSum, s)            
        return maxSum