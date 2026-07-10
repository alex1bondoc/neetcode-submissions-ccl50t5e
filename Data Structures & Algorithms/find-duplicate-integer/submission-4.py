class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        res = 0
        slow = 0
        fast = 0
        while True:
            slow = nums[slow]
            fast = nums[nums[fast]]
            if slow == fast:
                return slow