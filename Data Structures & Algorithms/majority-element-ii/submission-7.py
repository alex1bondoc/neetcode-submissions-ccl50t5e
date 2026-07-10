class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        cand1 = nums[0]
        cand2 = -float("inf")
        cnt1 = 1
        cnt2 = 0
        for i in range(1, n):
            num = nums[i]
            if num == cand1:
                cnt1 += 1
            elif num == cand2:
                cnt2 += 1
            else:
                cnt1 -= 1
                cnt2 -= 1
            if cnt2 < 0:
                cand2 = num
                cnt2 = 1
            if cnt2 > cnt1:
                cnt1, cnt2 = cnt2, cnt1
                cand1, cand2 = cand2, cand1
        cnt1 = 0
        cnt2 = 0
        for num in nums:
            if cand1 == num:
                cnt1 += 1
            if cand2 == num:
                cnt2 += 1
        if cnt1 > n // 3 and cnt2 > n // 3:
            return [cand1, cand2]
        if cnt1 > n // 3:
            return [cand1]
        return []