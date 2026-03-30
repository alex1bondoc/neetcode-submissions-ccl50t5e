class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        mini = nums[0]
        maxi = nums[0]
        res = nums[0]
        for i in range(1, len(nums)):
            x = nums[i]
            maxic = max(x, maxi * nums[i], mini * nums[i])
            minic = min(x, mini * nums[i], maxi * nums[i])
            res = max(res, maxic, minic)
            mini = minic
            maxi = maxic
        return res
