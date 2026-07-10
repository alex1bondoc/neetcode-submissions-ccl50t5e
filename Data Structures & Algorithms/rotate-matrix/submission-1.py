class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix) - 1
        k = (n + 1) // 2
        for i in range(k):
            for j in range(n):
                tl = matrix[i][j]
                tr = matrix[j][n - i]
                br = matrix[n - i][n - i - j]
                bl = matrix[n - i - j][i]
                matrix[i][j] = bl
                matrix[i + j][n - i] = tl
                matrix[n - i][n - i - j] = tr
                matrix[n - i - j][i] = br
                print(tl, tr, br, bl)
    
