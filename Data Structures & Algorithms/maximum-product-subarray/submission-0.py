class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        mini = min(nums[0], nums[1])
        maxi = max(nums[0], nums[1])
        res = max(mini, maxi, maxi * mini)
        for i in range(2, len(nums)):
            x = nums[i]
            maxi = max(x, maxi * nums[i], mini * nums[i])
            mini = min(x, mini * nums[i], maxi * nums[i])
            res = max(maxi, mini, maxi * mini)
        return res
