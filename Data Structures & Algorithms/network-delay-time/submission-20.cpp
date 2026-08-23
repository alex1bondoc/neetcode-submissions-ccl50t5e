class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, 1 << 29);
        d[k - 1] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        queue<int> q{};
        q.push(k - 1);
        while (q.size()) {
            int node{q.front()};
            q.pop();
            for (const auto& [v, cost] : adj[node]) {
                if (d[node] + cost < d[v]) {
                    q.push(v);
                    d[v] = d[node] + cost;
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
