#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF{std::numeric_limits<int>::max() / 2};
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        priority_queue<pair<int, int>> pq; // distance, node
        vector<int> d(n, INF), v(n);
        pq.push({0, k - 1});
        d[k - 1] = 0;
        while (pq.size()) {
            auto [distance, node] = pq.top();
            pq.pop();
            distance = -distance;
            v[node] = 1;
            for (const auto& [nei, di] : adj[node]) {
                if (v[nei] == 0 && di + distance < d[nei]) {
                    d[nei] = di + distance;
                    pq.push({-d[nei], nei});
                }
            }
        }
        int res{};
        for (int i : d) {
            if (i == INF) return -1;
            res = max(i, res);
        }
        return res;
    }
};
