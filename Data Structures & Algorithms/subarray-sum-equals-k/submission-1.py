class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        s = 0
        count = {0:1}
        for num in nums:
            s += num
            dif = s - k
            res += count.get(dif, 0)
            count[s] = count.get(s, 0) + 1
        return res