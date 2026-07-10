class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        r = len(nums) - 1
        i = l
        while i <= r:
            if nums[i] == 0:
                nums[l], nums[i] = nums[i], nums[l]
            elif nums[i] == 2:
                nums[r], nums[i] = nums[i], nums[r]
            i += 1
