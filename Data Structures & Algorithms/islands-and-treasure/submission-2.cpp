class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n{static_cast<int>(grid.size())}, m{static_cast<int>(grid[0].size())};
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto bfs = [&](int i, int j){
            q.push({i, j});
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (const auto& p : directions) {
                    int xx{x + p.first}, yy{y + p.second};
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] > grid[x][y] + 1) {
                        grid[xx][yy] = grid[x][y] + 1;
                        q.push({xx, yy});
                    }
                }
            }
        };

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j] == 0) {
                    bfs(i,j);
                }
            }
        }
        
    }
};
