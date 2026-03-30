class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        i = len(nums) - 1
        while True:
            if nums[i] == -1:
                return i + 1
            x = nums[i] - 1
            nums[i] = -1
            i = x