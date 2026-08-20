#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF{std::numeric_limits<int>::max() / 2};
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> distances(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        while (pq.size()) {
            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > distances[node]) {
                continue;
            }
            distances[node] = dis;
            for (const auto& [nei, d] : adj[node]) {
                pq.push({d + dis, nei});
            }
        }
        int res{};
        for (int d : distances) {
            if (d == INF) return -1;
            res = max(res, d);
        }

        return res;
    }
};
