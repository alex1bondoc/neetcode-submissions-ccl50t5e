class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n, m = len(s), len(t)
        
        memo = [[0] * (m + 1) for _ in range(n + 1)]

        memo[0][0] = 1
        for i in range(1, n + 1):
            for j in range(0, m + 1):
                if j == 0:
                    memo[i][j] = memo[i - 1][j]
                    continue
                if s[i - 1] == t[j - 1]:
                    memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j]
                else :
                    memo[i][j] = memo[i - 1][j] 
        print(memo)
        return memo[n][m]