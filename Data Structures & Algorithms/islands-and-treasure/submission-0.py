class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 0:
                    self.fill(grid, i, j)

    def fill(self, grid, i, j):
        visited = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        di = [0,1,0,-1]
        dj = [1,0,-1,0]
        q = deque([(i,j,0)])
        visited[i][j] = 1
        while q:
            x, y, d = q.popleft()
            grid[x][y] = min(grid[x][y], d)
            visited[x][y] = 1
            for k in range(4):
                xx = x + di[k]
                yy = y + dj[k]
                if xx >= 0 and yy >=0 and xx < len(grid) and yy < len(grid[0]) and visited[xx][yy] == 0 and grid[xx][yy] > 0:
                    q.append((xx, yy, d + 1))
        