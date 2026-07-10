class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return dp[0]
        dp = [0] * (n + 1)
        dp[0] = nums[0]
        dp[1] = nums[1]
        for i in range(2, n):
            for j in range(i - 2,-1, -1):
                dp[i] = max(dp[i], dp[j])
            dp[i] += nums[i]
        for i in range(0, n):
            dp[n] = max(dp[i], dp[n])
        return dp[n]