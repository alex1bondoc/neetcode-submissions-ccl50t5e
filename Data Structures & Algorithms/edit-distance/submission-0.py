class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        def rec(i, j):
            if i == n or j == m:
                return 0    
            if word1[i] == word2[j]:
                return rec(i + 1, j + 1)
            else :
                return 1 + min(rec(i, j + 1), rec(i + 1, j), rec(i + 1, j + 1))
            

        return rec(0, 0) + 1
        