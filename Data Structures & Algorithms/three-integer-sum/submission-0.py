class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        rez = []
        for i in range(len(nums)-2):
            for j in range(i +1, len(nums) - 1):
                for l in range(j + 1, len(nums)):
                    if nums[i] + nums[j] + nums[l] == 0:
                        aux = sorted([nums[i] , nums[j] , nums[l]])
                        if aux not in rez:
                            rez.append(aux)
        return rez