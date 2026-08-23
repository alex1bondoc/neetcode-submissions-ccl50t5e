class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges{};
        vector<int> p(points.size());
        for (int i{}; i < p.size(); ++i) {
            p[i] = i;
        }
        for (int i{}; i < points.size(); ++i) {
            for (int j{i + 1}; j < points.size(); ++j) {
                int dis{abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.push_back({dis, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int components{static_cast<int>(points.size())};
        int res{};
        int i{};
        auto find = [&](int node) {
            while (node != p[node]) {
                p[node] = p[p[node]];
                node = p[node];
            }
            return node;
        };
        while(components > 1) {
            auto edge = edges[i++];
            auto cost = edge[0];
            auto u = edge[1];
            auto v = edge[2];
            int pu{find(u)}, pv{find(v)};
            if (pu == pv) continue;
            if (pu > pv) swap(pu, pv);
            p[pu] = pv;
            components--;
            res += cost;
        }
        return res;
    }
};