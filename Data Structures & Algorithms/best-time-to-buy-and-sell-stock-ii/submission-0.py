class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dp = {}
        def rec(i, status):
            if i == len(prices):
                return 0
            if (i, status) in dp:
                return dp[(i, status)]
            res = rec(i + 1, status)
            if status:
                res = max(res, prices[i] + rec(i + 1, False))
            else :
                res = max(res, -prices[i] + rec(i + 1, True))
            dp[(i, status)] = res
            return res
        return rec(0, False)