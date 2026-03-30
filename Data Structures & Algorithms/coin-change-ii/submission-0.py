class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [[0] * (len(coins) + 1) for _ in range(amount + 1)]
        for j in range(len(coins) + 1):
            dp[0][j] = 1
        for i in range(1, amount + 1):
            for j in range(len(coins) + 1): 
                if j == 0:
                    dp[i][j] = 0
                else :
                    if i - coins[j - 1] >= 0:
                        dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j]
                    else :
                        dp[i][j] = dp[i][j - 1]
        return dp[amount][len(coins)]