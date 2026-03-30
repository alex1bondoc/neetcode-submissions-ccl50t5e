class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        rez = []

        nums.sort()
        for i in range(0, len(nums) - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            l = len(nums) - 1
            target = - nums[i]
            while j < l:
                if nums[j] + nums[l] < target:
                    j += 1
                elif nums[j] + nums[l] > target:
                    l -=1
                else :
                    rez.append([nums[i], nums[j], nums[l]])                    
                    while j < l and nums[j] == nums[j + 1]:
                        j += 1
                    while j < l and nums[l] == nums[l - 1]:
                        l -= 1
                    j += 1
                    l -= 1
        return rez