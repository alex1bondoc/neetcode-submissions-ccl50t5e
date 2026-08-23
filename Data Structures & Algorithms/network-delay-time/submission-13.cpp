class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        vector<int> visited(n, 1 << 30);
        visited[0] = 0;
        int res{};
        while (pq.size()) {
            auto [time, node] = pq.top();
            pq.pop();
            for (const auto [nei, cost]: adj[node]) {
                if (visited[nei] < cost + time) continue;
                pq.push({cost + time, nei});
                visited[nei] = cost + time;
            }

        }
        for (int d : visited) {
            if (d == 1 << 30) return -1;
            res = max(res, d);
        }
        return res;

    }
};
