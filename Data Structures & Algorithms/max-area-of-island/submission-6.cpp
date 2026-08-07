class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi{};
        int n{static_cast<int>(grid.size())}, m{static_cast<int>(grid[0].size())};
        auto bfs = [&](int i, int j){
            vector<pair<int, int>> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            queue<pair<int, int>> q;
            grid[i][j] = 0;
            q.push({i, j});
            int ans{1};
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                for (const auto& p : directions) {
                    int xx{x + p.first}, yy{y + p.second};
                    if (xx >= 0 && xx < grid.size() && yy >= 0 && yy < grid[0].size() && grid[xx][yy] == 1) {
                        grid[xx][yy] = 0;
                        ans++;
                        q.push({xx, yy});
                    }
                }
            }
            return ans;
        };

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (grid[i][j]) {
                    maxi = max(maxi, bfs(i, j));
                }
            } 
        }
        return maxi;
    }
};
