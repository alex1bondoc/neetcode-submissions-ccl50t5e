class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        i = 0
        l = 0
        k = n
        while i < n:
            if nums[i] == val:
                k -= 1
            else:
                nums[l] = nums[i]
                l += 1
            i += 1 
        return l