class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        di = [1,0,-1,0]
        dj = [0,1,0,-1]
        queue = deque([])
        normal = 0
        time = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    normal += 1
        while normal > 0 and queue:
            length = len(queue)
            for i in range(length):
                i, j = queue.popleft()
                for k in range(4):
                    ii = i + di[k]
                    jj = j + dj[k]
                    if ii in range(len(grid)) and jj in range(len(grid[0])) and grid[ii][jj] == 1:
                        grid[ii][jj] = 2
                        queue.append((ii, jj))
                        normal -= 1
            time += 1
        if normal >  0:
            return -1
        return time