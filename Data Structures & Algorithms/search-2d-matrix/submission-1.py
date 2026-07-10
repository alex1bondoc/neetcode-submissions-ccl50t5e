class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        aux = [a[0] for a in matrix]
        n = len(aux)
        l = 0
        r = n - 1
        row = -1
        while l <= r:
            mid = (l + r) // 2
            if aux[mid] < target:
                row = mid
                l = mid + 1
            else :
                r = mid - 1
        n = len(matrix[row])
        l = 0
        r = n -1
        print(row)
        while l <= r:
            mid = (l + r) // 2
            if matrix[row][mid] == target:
                return True
            elif matrix[row][mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False