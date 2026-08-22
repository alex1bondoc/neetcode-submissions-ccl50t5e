class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n{static_cast<int>(points.size())};
        vector<int> parents(n);
        for (int i{}; i < n; ++i) {
            parents[i] = i;
        }
        vector<vector<int>> edges{};
        for (int i{}; i < n; ++i) {
            for (int j{}; j < n; ++j) {
                if (i == j) continue;

                int dist{abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        auto find = [&](int node) {
            while (node != parents[node]) {
                parents[node] = parents[parents[node]];
                node = parents[node];
            }
            return node;
        };
        int cost{};
        for (const auto& edge : edges) {
            auto dist{edge[0]};
            auto x{edge[1]};
            auto y{edge[2]};
            int px{find(x)};
            int py{find(y)};
            if (px == py) continue;

            if (px > py) swap(px, py);
            parents[px] = py;
            cost += dist;
        }
        return cost;
    }
};