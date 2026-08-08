enum Ocean {
    PAC = 0,
    ATL = 1,
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n{static_cast<int>(heights.size())}, m{static_cast<int>(heights[0].size())};
        vector<vector<vector<int>>> visited(2, vector<vector<int>> (n, vector<int> (m, 0)));
        queue<pair<int, int>> pacQueue, atlQueue;
        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto bfs = [&](Ocean type){
            queue<pair<int, int>> q;
            if (type == Ocean::PAC) q = pacQueue;
            else q = atlQueue;

            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto& p : directions) {
                    int ii{i + p.first}, jj{j + p.second};
                    if (ii >=0 && jj >= 0 && ii < n && jj < m && !visited[type][ii][jj] && heights[ii][jj] >= heights[i][j]) {
                        visited[type][ii][jj] = 1;
                        q.push({ii, jj});
                    }
                }
            }
        };

        for (int i{}; i < n; ++i) {
            pacQueue.push({i, 0});
            atlQueue.push({i, m - 1});
            visited[Ocean::PAC][i][0] = 1;
            visited[Ocean::ATL][i][m - 1] = 1;
        }
        for (int i{}; i < m; ++i) {
            pacQueue.push({0, i});
            atlQueue.push({n - 1, i});
            visited[Ocean::PAC][0][i] = 1;
            visited[Ocean::ATL][n - 1][i] = 1;
        }
        bfs(Ocean::PAC);
        bfs(Ocean::ATL);
        vector<vector<int>> res{};
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (visited[Ocean::PAC][i][j] && visited[Ocean::ATL][i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
