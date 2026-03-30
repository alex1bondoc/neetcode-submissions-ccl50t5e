class Solution:
    def longestPalindrome(self, s: str) -> str:
        #dynamic programming
        resIdx, res = 0, 0
        n = len(s)

        dp = [[False] * n for _ in range(n)]

        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and ((j - i) <= 2 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    if res < (j - i + 1):
                        res = j - i + 1
                        resIdx = i
        return s[resIdx:resIdx + res]