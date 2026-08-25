#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        unordered_set<int> visited;
        vector<int> distance(n, std::numeric_limits<int>::max() / 2);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // minqueue
        pq.push({0, k - 1});
        while (pq.size() && visited.size() != n) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > distance[node]) continue;
            distance[node] = time;
            visited.insert(node);
            for (const auto& [nei, cost] : adj[node]) {
                if (visited.contains(nei)) continue;
                pq.push({cost + time, nei});
            }
        }
        int res{};
        for (int d : distance) {
            if (d == std::numeric_limits<int>::max() / 2) return -1;
            res = max(d, res);
        }
        return res;
    }
};
