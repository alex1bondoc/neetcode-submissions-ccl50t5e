class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix) - 1
        k = (n + 1) // 2
        for i in range(k):
            for j in range(i,n - i):
                tl = matrix[i][j]
                tr = matrix[j][n - i]
                br = matrix[n - i][n - j]
                bl = matrix[n - j][i]
                matrix[i][j] = bl
                matrix[j][n - i] = tl
                matrix[n - i][n - j] = tr
                matrix[n - j][i] = br
                print(tl, tr, br, bl)
