class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix) - 1
        n = len(matrix[0]) - 1
        res = []
        std = min(n, m)
        k = (std + 1) // 2 + (std + 1) % 2
        for i in range(k):    
            for j in range(i, n - i + 1):
                res.append(matrix[i][j])
            print(res)
            for j in range(i + 1, m - i + 1):
                res.append(matrix[j][n - i])
            print(res)

            for j in range(n - i - 1, i, -1):
                res.append(matrix[m - i][j])
            print(res)
            
            for j in range(m - i, i, - 1):
                res.append(matrix[j][i])
            print(res)

        return res