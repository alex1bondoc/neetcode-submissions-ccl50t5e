class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        dic = {}
        res = 0
        for num in nums:
            if num not in dic:
                dic[num] = dic.get(num - 1, 0) + dic.get(num + 1, 0) + 1
                dic[num - dic.get(num - 1, 0)] = dic[num]
                dic[num + dic.get(num + 1, 0)] = dic[num]
                res = max(res, dic[num])
        return res