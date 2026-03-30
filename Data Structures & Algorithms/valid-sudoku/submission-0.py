class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        squares = [set() for _ in range(9)]
        row = 0
        for elements in board:
            col = 0 
            for elem in elements:
                if elem == ".":
                    col += 1
                    continue
                sq = (row // 3) * 3 + (col // 3)
                if elem in rows[row]:
                    return False
                rows[row].add(elem)
                if elem in cols[col]:
                    return False
                cols[col].add(elem)

                if elem in squares[sq]:
                    return False
                squares[sq].add(elem)
                
                col += 1
            row += 1
        return True
