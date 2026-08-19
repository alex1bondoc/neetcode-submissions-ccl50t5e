#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int INF{std::numeric_limits<int>::max() / 2};
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        priority_queue<int, vector<int>, grreat34cev5&481=
    }
};
