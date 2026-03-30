class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        hashSet = set(nums)
        res = 0
        for num in nums:
            if num + 1 in hashSet:
                continue
            cnt, x = 0, num
            while x in hashSet:
                cnt += 1
                x -= 1
            if cnt > res:  
                res = cnt

        return res