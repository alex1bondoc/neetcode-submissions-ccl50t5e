class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            nums[i] = max(nums[i], 0)
        for i in range(n):
            num = abs(nums[i])
            if 0 < num <=n:
                if nums[num - 1] > 0:
                    nums[num - 1] *= -1
                elif nums[num - 1] == 0:
                    nums[num - 1] = -1
        print(nums)
        for i in range(n):
            if nums[i] >= 0:
                return i + 1
        return n + 1