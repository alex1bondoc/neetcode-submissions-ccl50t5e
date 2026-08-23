#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> visited(n, 1 << 30);

        visited[k - 1] = 0;
        pq.push({0, k - 1});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Sărim peste intrările învechite din coadă
            if (time > visited[node]) continue;

            for (const auto& [nei, cost] : adj[node]) {
                if (cost + time < visited[nei]) {
                    visited[nei] = cost + time;
                    pq.push({visited[nei], nei});
                }
            }
        }

        int res = 0;
        for (int d : visited) {
            if (d == (1 << 30)) return -1;
            res = max(res, d);
        }
        return res;
    }
};