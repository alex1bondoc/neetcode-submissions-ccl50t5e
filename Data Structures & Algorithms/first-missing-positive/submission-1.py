class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        res = 1
        dic = set()
        for num in nums:
            if num < 0:
                continue
            dic.add(num)
            while res in dic:
                res += 1
        return res if res > 0 else 0
