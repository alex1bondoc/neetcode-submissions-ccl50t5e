class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max = 0
        mini = prices[0]
        for i in range(1, len(prices)):
            if prices[i] < mini:
                mini = prices[i]
            else :
                if prices[i] - mini> max:
                    max = prices[i] - mini
        return max
