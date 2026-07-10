class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix) - 1
        n = len(matrix[0]) - 1
        res = []
        std = min(n, m)
        k = (std + 1) // 2 + (std + 1) % 2
        for i in range(k):
            for j in range(i, n - i):
                res.append(matrix[i][j])
            for j in range(i, m - i):
                res.append(matrix[j][n - i])
            for j in range(n - i, i, -1):
                res.append(matrix[m - i][j])
            for j in range(m - i, i, - 1):
                res.append(matrix[j][i])
        if n == m and n % 2 == 0:
            res.append(matrix[(n + 1) // 2][(n + 1) // 2])
        return res