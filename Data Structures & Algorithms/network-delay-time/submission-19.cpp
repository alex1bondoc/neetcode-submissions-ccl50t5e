class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, 1 << 29);
        d[k - 1] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        for (int k{}; k < n - 1; ++k) {
            for (int u{}; u < n; ++u) {
                for (const auto& [v, cost] : adj[u]) {
                    d[v] = min(d[v], d[u] + cost);
                }
            }
        }
        int res{};
        for (int i : d) {
            if (i == 1 << 29) return -1;
            res = max(res, i);
        }
        return res;
    }
};
