class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> visited(grid.size(), vector<int> (grid.size(), 0));
        visited[0][0] = 1;
        while (pq.size()) {
            auto v = pq.top();
            pq.pop();
            auto cost{v[0]}, row{v[1]}, col{v[2]};
        
            if (row == grid.size() - 1 && col == grid.size() - 1) return cost;
            for (const auto& dir : directions) {
                int xx{dir[0] + row}, yy{dir[1] + col};
                if (xx < 0 || xx >= grid.size() || yy < 0 || yy >= grid.size() || visited[xx][yy]) continue;
                pq.push({max(cost, grid[xx][yy]), xx, yy});
                visited[xx][yy] = 1;
            }
        }

        return -1;
    }
};
