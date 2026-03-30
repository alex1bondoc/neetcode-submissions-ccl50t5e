class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = len(nums) - 1
        for j in range(len(nums) - 2, -1, -1):
            if nums[j] + j >= i:
                i = j

        if i == 0:
            return True
        return False        