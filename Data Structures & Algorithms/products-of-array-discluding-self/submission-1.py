class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1] * len(nums)
        sufix = [1] * len(nums)
        for i in range(len(nums)):
            if i > 0:
                prefix[i] = prefix[i - 1] * nums[i-1]
        for i in range(len(nums),-1, -1):
            if i < len(nums) - 1:
                sufix[i] = sufix[i + 1] * nums[i+1]

        return [prefix[i] * sufix[i] for i in range(len(nums))]

        