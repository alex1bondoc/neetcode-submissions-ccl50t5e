class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        int n{static_cast<int>(grid.size())};
        vector<vector<int>> visited(n, vector<int>(n));
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        visited[0][0] = 1;
        pq.push({grid[0][0], 0, 0});
        int res{};
        while (pq.size()) {
            auto top = pq.top();
            pq.pop();
            auto dist{top[0]};
            auto row{top[1]};
            auto col{top[2]};
            res = dist;
            cout << row << " " << col << endl;
            for (const auto& direction : directions) {
                int xx{row + direction[0]}, yy{col + direction[1]};
                if (xx >= 0 && xx < n && yy >= 0 && yy < n && visited[xx][yy] == 0) {
                    if (xx == n - 1 && yy == n - 1) 
                        return max(grid[xx][yy], dist);
                    pq.push({max(grid[xx][yy], dist), xx, yy});
                    visited[xx][yy] = 1;
                }
            }
        }
        return res;

    }
};
