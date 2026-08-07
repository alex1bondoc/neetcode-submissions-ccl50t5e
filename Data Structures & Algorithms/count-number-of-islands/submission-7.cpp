class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt{};
        int n{static_cast<int>(grid.size())}, m{static_cast<int>(grid[0].size())};

        auto bfs = [&](int i, int j){
            queue<pair<int, int>> q{};
            q.push({i, j});
            vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            grid[i][j] = '0';
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                
                for (const auto& p : directions) {
                    int xx{x + p.first}, yy{y + p.second};
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == '1') {
                        q.push({xx, yy});
                        grid[xx][yy] = '0';
                    }
                }
            }
        };
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j] == '1') {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }   
};
