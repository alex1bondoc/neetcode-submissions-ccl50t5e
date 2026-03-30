class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        cnt = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    cnt += 1
                    self.search(grid, i, j)

        return cnt 
    def search(self, grid, i, j):
        queue = deque([(i, j)])
        di = [1,0,-1,0]
        dj = [0,1,0,-1]
        while queue:
            x, y = queue.popleft()
            grid[x][y] = "0"
            for k in range(4):
                xx = x + di[k]
                yy = y + dj[k]
                if xx >= 0 and xx < len(grid) and yy >= 0 and yy < len(grid[0]) and grid[xx][yy] == "1":
                    queue.append((xx, yy))
        
