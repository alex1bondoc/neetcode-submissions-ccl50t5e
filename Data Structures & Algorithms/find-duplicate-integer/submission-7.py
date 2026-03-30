class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        x = 0
        while nums[x] != 0:
            y = nums[x]
            nums[x] = 0
            x = y
        return x