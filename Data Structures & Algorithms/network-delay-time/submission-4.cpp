#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // DFS solution
        int INF{std::numeric_limits<int>::max() };
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> distances(n, INF);
        auto dfs = [&](auto self, int node, int distance) -> void{
            if (distances[node] > distance) {
                distances[node] = distance;
                for (const auto& [nei, d] : adj[node]) {
                    self(self, nei, d + distance);
                }
            }
        };
        dfs(dfs, k - 1, 0);
        int res{};
        for (const int& distance : distances) {
            if (distance == INF) return -1;
            res = max(distance, res);
        }
        return res;
    }
};
