class Solution {
    public int orangesRotting(int[][] grid) {
        Deque<int[]> queue = new ArrayDeque<>();
        int minutes = 0;
        int fresh = 0;
        for (int i = 0; i < grid.length; i ++) {
            for (int j = 0; j < grid[0].length; j ++) {
                if (grid[i][j] == 2) {
                    queue.addLast(new int[]{i, j});
                }
                else if(grid[i][j] == 1){
                    fresh += 1;
                }
            }
        }
        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (fresh > 0 && queue.size() > 0) {
            int n = queue.size();
            for(int i = 0; i < n; i ++) {
                int[] aux = queue.removeFirst();
                for( int[] dir :directions) {
                    int row = aux[0] +  dir[0];
                    int col = aux[1] + dir[1];
                    if (row >=0 && row < grid.length && col >=0 && col < grid[0].length && grid[row][col] == 1) {
                        grid[row][col] = 2;
                        queue.addLast(new int[]{row, col});
                        fresh --;
                    }
                }                
            }
            minutes += 1;
        }
        return fresh == 0 ? minutes : -1;
    }
}
