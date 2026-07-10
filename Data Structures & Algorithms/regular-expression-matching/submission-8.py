class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[0] * (len(p) + 1) for _ in range(len(s) + 1)]
        dp[0][0] = 1
        for i in range(1, len(s) + 1):
            for j in range(0, len(p) + 1):
                if j == 0:
                    dp[i][j] = 1
                else :
                    if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                    elif p[j - 1] == '*':
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                    else :
                        dp[i][j] = dp[i - 1][j]
        print(dp)
        return dp[len(s)][len(p)] > 0