#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        vector<int> distance(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k - 1});
        distance[k - 1] = 0;
        while (pq.size()) {
            auto [cost, node] = pq.top();
            pq.pop();
            if (cost > distance[node]) continue;
            for (const auto& [nei, time] : adj[node]) {
                if (time + cost >= distance[nei]) continue;
                distance[nei] = time + cost;
                pq.push({time + cost, nei});
            }
        }
        int res = 0;
        for (int d : distance) {
            if (d == INF) return -1;
            res = max(d, res);
        }
        return res;
    }
};