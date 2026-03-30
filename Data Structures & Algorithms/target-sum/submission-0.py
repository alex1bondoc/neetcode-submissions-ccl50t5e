class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dic = {0:0}
        def aux(sum, i) -> int:
            if sum == target and i == n:
                return 1
            if i == n:
                return 0
            return aux(sum + nums[i], i + 1) + aux(sum - nums[i], i + 1)

        return aux(0, 0)