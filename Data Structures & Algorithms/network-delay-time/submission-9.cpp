#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF{std::numeric_limits<int>::max() / 2};
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        queue<pair<int, int>> q;
        vector<int> d(n, INF), v(n);
        q.push({k - 1, 0});
        d[k - 1] = 0;
        while (!q.empty()) {
            auto [node, distance] = q.front();
            q.pop();
            if (d[node] < distance) continue;
            for (auto [nei, di] : adj[node]) {
                if (distance + di < d[nei]) {
                    d[nei] = distance + di;
                    q.push({nei, distance + di});
                }
            }
        }
        int res = 0;
        for (const auto& time: d) {
            res = max(res, time);
        }
        return res == INF ? -1 : res;
    }
};
