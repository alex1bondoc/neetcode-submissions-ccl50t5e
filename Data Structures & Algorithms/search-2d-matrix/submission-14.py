class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows, cols = len(matrix), len(matrix[0])
        total = rows * cols - 1
        l, r = 0, total

        while l <= r:
            mid = (l + r) // 2
            row = mid // cols
            c = mid % cols
            if matrix[row][c] == target:
                return True
            elif matrix[row][c] > target:
                r = mid - 1
            else :
                l = mid + 1
        return False