class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n{static_cast<int>(board.size())}, m{static_cast<int>(board[0].size())};

        vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto visited = board;
        queue<pair<int, int>> q;
        auto bfs = [&]() {
            while (q.size()) {
                auto [i, j] = q.front();
                q.pop();
                for (const auto& p : directions) {
                    int ii{i + p.first}, jj{j + p.second};
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m && visited[ii][jj] == 'O') {
                        visited[ii][jj] = 'X';
                        q.push({ii, jj});
                    }
                }
            }
        };
        for (int i{}; i < n; ++i) {
            if (visited[i][0] == 'O'){
                q.push({i, 0});
                visited[i][0] = 'X';

            }
            if (visited[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = 'X';
            }
        }
        for (int i{}; i < m; ++i) {
            if (visited[0][i] == 'O'){
                q.push({0, i});
                visited[0][i] = 'X';

            }
            if (visited[n - 1][i] == 'O') {
                q.push({n - 1, i});
                visited[n - 1][i] = 'X';
            }
        }
        bfs();
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                if (board[i][j] == 'O' && visited[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
