class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        res = 0
        help = float("inf")
        for num in prices:
            if num < help:
                help = num
            else:
                res += num - help
                help = num
        return res