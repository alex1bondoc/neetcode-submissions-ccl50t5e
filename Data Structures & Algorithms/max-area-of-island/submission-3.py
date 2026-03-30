class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        cnt = 0
        maxi = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    cnt += 1
                    x = self.search(grid, i, j)
                    print(x)
                    maxi = max(maxi, x)
        return maxi
    def search(self, grid, i, j) -> int:
        queue = deque([(i, j)])
        di = [1,0,-1,0]
        dj = [0,1,0,-1]
        cnt1 = 0
        grid[i][j] = 0
        while queue:
            x, y = queue.popleft()
            cnt1 += 1
            for k in range(4):
                xx = x + di[k]
                yy = y + dj[k]
                if xx >= 0 and xx < len(grid) and yy >= 0 and yy < len(grid[0]) and grid[xx][yy] == 1:
                    queue.append((xx, yy))
                    grid[xx][yy] = 0

                    print(xx, yy)
        return cnt1
