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
                cnt2 -= 1
            if cnt2 < 0 :
                cand2 = num
                cnt2 = 1
            if cnt2 > cnt1:
                cnt1, cnt2 = cnt2, cnt1
                cand1, cand2 = cand2, cand1
        cnt1 = 0
        cnt2 = 0
        res = []
        for num in nums:
            if num == cand1:
                cnt1 += 1
            if num == cand2:
                cnt2 += 1
        if cnt1 >  len(nums) //3:
            res.append(cand1)
        if cnt2 > len(nums) // 3:
            res.append(cand2)
        return res    
