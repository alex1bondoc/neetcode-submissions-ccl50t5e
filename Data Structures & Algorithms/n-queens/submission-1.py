class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.col = 0
        self.diag = 0
        self.diagsec = 0
        res = []
        def back(k, board):
            if k == n:
                aux = [["." if i != x else "Q" for i in range(n)] for x in board]
                res.append( ["".join(r) for r in aux])
                return
            for i in range(n):
                print(board)
                if (1 << i) & self.col or (1 <<(k + i)) & self.diag or (1 <<(k- i + n - 1)) & self.diagsec:
                    continue
                
                self.col |= 1 << i
                self.diag |= 1 << (k + i)
                self.diagsec |= 1 <<(k - i + n - 1)
                board.append(i)
                back(k + 1, board)
                board.pop()
                self.col ^= 1 << i
                self.diag ^= 1 << (k + i)
                self.diagsec ^= 1 <<(k - i + n - 1)
        back(0, [])
        return res