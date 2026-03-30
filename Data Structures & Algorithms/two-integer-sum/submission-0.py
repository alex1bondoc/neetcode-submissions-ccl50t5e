class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = {}
        sol  = [1000, 1000]
        for i in range(len(nums)):
            if target - nums[i] in hash: 
                if hash[target - nums[i]] < sol[0]:
                    sol = [hash[target - nums[i]], i]
            if nums[i] not in hash:
                hash[nums[i]] = i
        
        return sol
        