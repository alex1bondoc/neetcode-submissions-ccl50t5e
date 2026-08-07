#include <vector>
#include <queue>

using namespace std;

enum class Ocean {
    PAC = 0,
    ATL = 1
};

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> res;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // ocean[i][j][0] pentru Pacific, ocean[i][j][1] pentru Atlantic
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));

        auto bfs = [&](Ocean type) {
            queue<pair<int, int>> q;
            int o_idx = static_cast<int>(type);

            // 1. Introducem toate celulele de pe marginea oceanului respectiv în coadă
            for (int i = 0; i < n; ++i) {
                int j = (type == Ocean::PAC) ? 0 : m - 1;
                visited[i][j][o_idx] = true;
                q.push({i, j});
            }
            for (int j = 0; j < m; ++j) {
                int i = (type == Ocean::PAC) ? 0 : n - 1;
                if (!visited[i][j][o_idx]) { // Evităm colțurile dublate
                    visited[i][j][o_idx] = true;
                    q.push({i, j});
                }
            }

            // 2. Rulăm BFS invers (de la apă spre munte, în sus sau la egalitate)
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                for (const auto& [dx, dy] : directions) {
                    int xx = x + dx;
                    int yy = y + dy;

                    // Verificăm dacă suntem în matrice, nevizitați și dacă apa poate curge (heights[xx][yy] >= heights[x][y])
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        if (!visited[xx][yy][o_idx] && heights[xx][yy] >= heights[x][y]) {
                            visited[xx][yy][o_idx] = true;
                            q.push({xx, yy});
                        }
                    }
                }
            }
        };

        // Rulăm Multi-source BFS pentru ambele oceane
        bfs(Ocean::PAC);
        bfs(Ocean::ATL);

        // 3. Celulele care au ajuns în ambele oceane sunt adăugate în rezultat
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j][0] && visited[i][j][1]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};