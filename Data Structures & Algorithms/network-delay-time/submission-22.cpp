class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, 1 << 29);
        d[k - 1] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        priority_queue<pair<int, int>> pq;
        pq.push({0, k - 1});
        d[k - 1] = 0;
        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();
            cost = -cost;
            if (cost > d[node]) continue;
            d[node] = cost;
            for (const auto& [v, time] : adj[node]) {
                if (cost + time < d[v]) {
                    d[v] = cost + time;
                    pq.push({-d[v], v});
                }
            }
        }
        int res{};
        for (int x : d) {
            if (x == 1 << 29) return -1; 
            res = max(res, x);
        }
        return res;
    }
};
