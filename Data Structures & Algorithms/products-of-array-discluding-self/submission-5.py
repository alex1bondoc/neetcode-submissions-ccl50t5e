class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        pre = [1] * n
        suf = [1] * n
        pre[0] = nums[0]
        suf[n - 1] = nums[n - 1]
        for i in range(1, n - 1):
            pre[i] = pre[i - 1] * nums[i]
            suf[n - 1 - i] = suf[n - i] * nums[n - 1 - i]
        res = []
        for i in range(0, n):
            if i == 0:
                res.append(suf[1])
            elif i == n - 1:
                res.append(pre[n - 2])
            else :
                res.append(suf[i + 1] * pre[i - 1])
        return res