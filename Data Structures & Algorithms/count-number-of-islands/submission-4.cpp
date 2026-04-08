class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    islands ++;
                    bfs(grid, i, j);
                }
            }
        }
        return islands;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
        return ;
    }
    void bfs(vector<vector<char>>& grid, int r, int c) {
        std::queue<pair<int, int>> q{};
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        q.push({r, c});
        grid[r][c] = '0';
        while (!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; ++k) {
                int newI = i + di[k];
                int newJ = j + dj[k];
                if (newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size() || grid[newI][newJ] == '0'){
                    continue;
                }
                q.push({newI, newJ});
                grid[newI][newJ] = '0';
            }
        } 
        return;

    } 
};
