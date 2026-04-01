class Solution {
    public void islandsAndTreasure(int[][] grid) {
        for(int i = 0; i <  grid.length; i ++) {
            for (int j = 0; j < grid[0].length; j ++) {
                if (grid[i][j] == 0) {
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
    public void dfs(int[][] grid, int r, int c, int cnt){
        if (r < 0 || c < 0 || r >= grid.length || c >= grid[0].length || grid[r][c] < 0 || grid[r][c] < cnt) {
            return;
        }
        int i = r;
        int j = c;
        grid[i][j] = cnt;
        dfs(grid, i + 1, j, cnt + 1);
        dfs(grid, i - 1, j, cnt + 1);
        dfs(grid, i, j + 1, cnt + 1);
        dfs(grid, i, j - 1, cnt + 1);
    }
}
