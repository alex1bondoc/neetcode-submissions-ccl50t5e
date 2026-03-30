class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        res = 1
        memo = {}
        d = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        
        def dfs(i, j) -> int:
            if (i, j) in memo:
                return memo[(i, j)]
            maxi = 0
            for x, y in d:
                ii = x + i
                jj = y + j
                if ii >=0 and ii < len(matrix) and jj >=0 and jj < len(matrix[0]) and matrix[ii][jj] > matrix[i][j]:
                    maxi = max(maxi, dfs(ii, jj))
            memo[(i, j)] = maxi + 1
            return maxi + 1
        
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = max(res, dfs(i, j))
        print(memo)
        return res