class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        s = 0
        dic = {0:1}
        for num in nums:
            s += num
            dif = s - k
            res += dic.get(dif, 0)
            dic[s] = 1 + dic.get(s, 0)
        return res