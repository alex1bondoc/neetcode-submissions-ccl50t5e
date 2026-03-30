class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        pac, atl = set(), set()

        def dfs(i, j, ocean, height):
            if (i, j) in ocean or i < 0 or j < 0 or i == n or j == m or heights[i][j] < height:
                return
            ocean.add((i, j))
            dfs(i + 1, j, ocean, heights[i][j])
            dfs(i - 1, j, ocean, heights[i][j])
            dfs(i , j + 1, ocean, heights[i][j])
            dfs(i , j - 1, ocean, heights[i][j])
        for c in range(m):
            dfs(0, c, pac, heights[0][c])
            dfs(n - 1, c, atl, heights[n - 1][c])
        for c in range(n):
            dfs(c, 0, pac, heights[c][0])
            dfs(c, m - 1, atl, heights[c][m - 1])

        res = []
        for i in range(n):
            for j in range(m):
                if (i, j) in pac and (i, j) in atl:
                    res.append((i, j))

        return res