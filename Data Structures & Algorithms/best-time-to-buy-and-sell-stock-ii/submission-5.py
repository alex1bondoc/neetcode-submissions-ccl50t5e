class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        mini = float("inf")
        res = 0
        for i in range(len(prices)):
            price = prices[i]
            if price < mini:
                mini = price
            else:
                res += price - mini
                mini = price
        return res