class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        cand1 = nums[0]
        cand2 = float("-inf")
        cnt1 = 1
        cnt2 = 0
        for i in range(len(nums)):
            num = nums[i]
            if num == cand1:
                cnt1 += 1
            elif num == cnt2:
                cnt2 += 1
            else :
                cnt1 -= 1
                cnt2 -= 1
            if cnt2 < 0:
                cand2 = num
                cnt2 = 1
            if cnt2 > cnt1:
                cnt1, cnt2 = cnt2, cnt1
                cand1, cand2 = cand2, cand1
        if cnt1 > 0 and cnt2 >= 0 and cand2 != float("-inf"):
            return [cand1, cand2]
        if cnt1 > 0:
            return [cand1]
        return []
