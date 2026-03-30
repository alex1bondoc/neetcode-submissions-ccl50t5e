class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = nums[0]
        cnt = 1
        for i in range(1, len(nums)):
            if nums[i] == candidate:
                cnt += 1
            else :
                if cnt == 0:
                    candidate = nums[i]
                    cnt = 1
                else :
                    cnt -= 1
        return candidate