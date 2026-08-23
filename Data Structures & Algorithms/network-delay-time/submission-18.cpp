class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // floyd warshal
        vector<vector<int>> d(n, vector<int> (n, 1 << 29));
        for (int i{}; i < n; ++i) {
            d[i][i] = 0;
        }
        for (const auto& time : times) {
            d[time[0] - 1][time[1] - 1] = time[2];
        }
        for (int mid{}; mid < n; ++mid) {
            for (int u{}; u < n; ++u) {
                for (int v{}; v < n; ++v) { 
                    d[u][v] = min(d[u][v], d[u][mid] + d[mid][v]);
                }
            }
        }
        for (int i{}; i < n; ++i) {
            for (int j{}; j < n; ++j) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        int res{};
        for (int x : d[k - 1]) {
            if (x == 1 << 29) return -1; 
            res = max(res, x);
        }
        return res;
    }
};
