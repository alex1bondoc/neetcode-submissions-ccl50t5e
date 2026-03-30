class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        board = [["."] * n for i in range(n)]
        aux = [-1] * n
        def backtracking(k):
            if k == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return 
            for c in range(n):
                ok = True
                for i in range(k):
                    if c == aux[i]:
                        ok = False
                    if i + c == k + aux[i]:
                        ok =  False
                    if i + aux[i] == k + c:
                        ok = False
                if ok == False:
                    continue
                else:
                    aux[k] = c
                    board[k][c] = "Q"
                    backtracking(k + 1)
                    aux[k] = -1
                    board[k][c] = "."
        backtracking(0)
        return res
