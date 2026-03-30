class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dic = {}
        def aux(sum, i) -> int:
            if sum == target and i == n:
                return 1
            if i == n:
                return 0
            if (sum, i) in dic:
                return dic[(sum, i)]
            dic[(sum, i)] = aux(sum + nums[i], i + 1) + aux(sum - nums[i], i + 1)
            return dic[(sum, i)]

        return aux(0, 0)