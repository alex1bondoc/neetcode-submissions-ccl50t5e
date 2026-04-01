class Solution {
    private int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int n = heights.length;
        int m = heights[0].length;
        boolean[][] pacific = new boolean[n][m];
        boolean[][] atlantic = new boolean[n][m];

        Queue<int[]> pacQ = new LinkedList<>();
        Queue<int[]> atlQ = new LinkedList<>();
        for (int c = 0; c < m; c++) {
            pacQ.add(new int[]{0, c});
            atlQ.add(new int[]{n - 1, c});
        }
        for (int r = 0; r < n; r++) {
            pacQ.add(new int[]{r, 0});
            atlQ.add(new int[]{r, m - 1});
        }
        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j< m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.add(Arrays.asList(i,j));
                }
            }
        }
        return res;
    }
    public void bfs(Queue<int[]> q, boolean[][] ocean, int[][] heights){
        while(q.size() > 0) {
            int[] cur = q.poll();
            int r = cur[0], c = cur[1];
            ocean[r][c] = true;
            for(int[] dir: directions){
                int rr = r + dir[0], cc = c + dir[1];
                if (rr >= 0 && rr < heights.length && cc >=0 && cc < heights[0].length && !ocean[rr][cc] && heights[rr][cc] >= heights[r][c]){
                    q.add(new int[]{rr, cc});
                }
            }
        }
    }
}
