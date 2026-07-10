class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        if m < n:
            m, n = n, m
            s, t = t, s
        memo = [[0] * (n + 1) for _ in range(m + 1)]

        memo[0][0] = 1
        for i in range(1, m + 1):
            for j in range(0, n + 1):
                if j == 0:
                    memo[i][j] = memo[i - 1][j]
                    continue
                if t[i - 1] == s[j - 1]:
                    memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j]
                else :
                    memo[i][j] = memo[i - 1][j] 
        print(memo)
        return memo[m][n]