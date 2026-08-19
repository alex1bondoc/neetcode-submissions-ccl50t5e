#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF{std::numeric_limits<int>::max() / 2};
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> distance(n, INF);
        distance[k - 1] = 0;
        for (int m{}; m < n; ++m) {
            for (const auto& time : times) {
                int u{time[0] - 1}, v{time[1] - 1};
                if (distance[v] > distance[u] + time[2]) {
                    distance[v] = distance[u] + time[2];
                }
            }
        }
        int res{};
        for (const int& d : distance) {
            res = max(res, d);
            if (d == INF) return -1;
        }
        return res;
    }
};
