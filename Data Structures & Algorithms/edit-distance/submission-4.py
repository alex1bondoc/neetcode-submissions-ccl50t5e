class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        memo = {}
        def rec(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            if i == n:
                memo[(i, j)] = m - j
                return m - j
            if j == m:
                memo[(i, j)] = n - i
                return n - i
            if word1[i] == word2[j]:
                if (i + 1, j + 1) not in memo:
                    memo[(i + 1, j + 1)] = rec(i + 1, j + 1)
                return memo[(i + 1, j + 1)]
            else :
                if (i, j + 1) not in memo:
                    memo[(i, j + 1)] = rec(i, j + 1)
                if (i + 1, j + 1) not in memo:
                    memo[(i + 1, j + 1)] = rec(i + 1, j + 1)
                if (i + 1, j) not in memo:
                    memo[(i + 1, j)] = rec(i + 1, j)    
                memo[(i, j)] = 1 + min(memo[(i, j + 1)], memo[(i + 1, j)], memo[(i + 1, j + 1)])
                return memo[(i, j)]
            

        return rec(0, 0)
        return memo[(0, 0)]
        