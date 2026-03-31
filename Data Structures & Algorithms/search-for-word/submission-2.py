class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def back(r, c, i):
            if i == len(word):
                return True
            if r < 0 or r>= len(board) or c < 0 or c >= len(board[0]) or board[r][c] == "$" or board[r][c] != word[i]:
                return False
            temp = board[r][c]
            board[r][c] = "$"
            result = back(r + 1, c, i + 1) or back(r - 1, c, i + 1) or back(r, c + 1, i + 1) or back(r, c - 1, i + 1)
            board[r][c] = temp
            return result
        for i in range(len(board)):
            for j in range(len(board[0])):
                if back(i, j, 0):
                    return True

        return False