class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]        

        def aux(houses):
            if len(houses) == 0:
                return 0
            if len(houses) == 1:
                return houses[0]
            dp = [-1] * (len(houses))
            dp[0] = houses[0]
            dp[1] = max(houses[1], houses[0])
            for i in range(2, len(houses)):
                dp[i] = max(dp[i - 1], dp[i - 2] + houses[i])
            return dp[len(houses) - 1]

        return max(aux(nums[:-1]), aux(nums[1:]))