class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n, m = len(board), len(board[0])

        
        def dfs(i, j):
            if i < 0 or j < 0 or i == n or j == m or board[i][j] != "O":
                return 
            print(i, j)
            
            board[i][j] = "$"
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)


        for i in range(n):
            if board[i][0] == "O":
                dfs(i, 0)
            if board[i][m - 1]:
                dfs(i, m - 1)
        for i in range(m):
            if board[0][i] == "O":
                dfs(0, i)
            if board[n - 1][i]:
                dfs(n-1, i)
        print(board)
        for i in range(n):
            for j in range(m):
                if board[i][j] == "$":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
