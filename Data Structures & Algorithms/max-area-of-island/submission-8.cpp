class Solution {
public:
    int findArea(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
        if(visited[i][j]) return 0;
        visited[i][j] = true;
        int curr = 0;
        if(i-1>=0 && grid[i-1][j]==1) curr += findArea(grid, visited, i-1, j, n, m);
        if(i+1<n && grid[i+1][j]==1) curr += findArea(grid, visited, i+1, j, n, m);
        if(j-1>=0 && grid[i][j-1]==1) curr += findArea(grid, visited, i, j-1, n, m);
        if(j+1<m && grid[i][j+1]==1) curr += findArea(grid, visited, i, j+1, n, m);
        return 1 + curr;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    res = max(res, findArea(grid, visited, i, j, n, m));
                }
            }
        }
        return res;
    }
};
