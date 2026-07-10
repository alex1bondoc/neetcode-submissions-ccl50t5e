class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        i = 0 
        res = []
        while i < len(nums):
            if nums[i] >= 0:
                break
            l = i + 1
            r = len(nums) - 1
            while l < r:
                sum = nums[i] + nums[l] + nums[r]
                if sum == 0:
                    res.append([nums[i], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < len(nums) and nums[l] == nums[l - 1]:
                        l += 1
                elif sum > 0:
                    r -= 1
                else :
                    l += 1
            i += 1
            while i < len(nums) and nums[i] == nums[i - 1]:
                i+=1
        return res