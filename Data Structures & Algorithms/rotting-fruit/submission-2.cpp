class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n{static_cast<int>(grid.size())}, m{static_cast<int>(grid[0].size())};
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time{0};
        int cnt{};
        auto bfs = [&](){
            while (q.size()) {
                int size{static_cast<int>(q.size())};
                for (int i{}; i < size; ++i) {
                    cnt--;
                    auto [x, y] = q.front();
                    q.pop();
                    for (const auto& p : directions) {
                        int xx{x + p.first}, yy{y + p.second};
                        if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == 1) {
                            grid[xx][yy] = 0;
                            q.push({xx, yy});
                        }
                    }
                }
                if (q.size()) time++;
            }
        };

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = 0;
                    cnt++;
                }
                if (grid[i][j] == 1) cnt++;
            }
        }
        bfs();
        return cnt == 0 ? time : -1;
    }
};
