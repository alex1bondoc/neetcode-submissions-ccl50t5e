#include <limits>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int m) {
        // floyd warshall
        const long long INF{std::numeric_limits<int>::max()};
        vector<vector<long long>> distances(n, vector<long long>(n, INF));
        for (int i{}; i < n; ++i) {
            distances[i][i] = 0;
        }
        for (const auto& time : times) {
            distances[time[0] - 1][time[1] - 1] = time[2];
        }
        for (int k{}; k < n; ++k) {
            for (int i{}; i < n; ++i) {
                for (int j{}; j < n; ++j) {
                    if (distances[i][j] > distances[i][k] + distances[k][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
                }
            }
        }
        long long res{};
        for (const auto& d : distances[m - 1]) {
            res = std::max(d, res);
        }
        // for (int i{}; i < n; ++i, cout << endl) {
        //     for (int j{}; j < n; ++j) {
        //         cout << distances[i][j] << " ";
        //     }
        // }
        return res == INF ? -1 : res;
    }
};
