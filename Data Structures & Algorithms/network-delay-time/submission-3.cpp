class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> distance(n + 1, 1 << 30);
        distance[0] = -1;
        auto dfs = [&](auto self, int node, int dist) -> void {
            if (distance[node] > dist) {
                distance[node] = dist;
                for (const auto& [nei, d] : adj[node]) {
                    self(self, nei, d + dist);
                }
            }
        };

        dfs(dfs, k, 0);
        int res{};
        for (const int& d : distance) {
            if (d == 1 << 30) return -1;
            res = max(res, d);
        }        
        return res;
    }
};
