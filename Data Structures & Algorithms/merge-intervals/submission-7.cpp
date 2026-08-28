class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxval{};
        for (const auto& interval : intervals) {
            maxval = max(maxval, interval[0]);
        }
        vector<int> c(maxval + 1, -1);
        for (const auto& interval : intervals) {
            c[interval[0]] = max(c[interval[0]], interval[1]);
        }
        cout << maxval <<endl;
        vector<vector<int>> res;
        int start{-1};
        int end{-1};
        for (int i{}; i <= maxval; ++i) {
            if (c[i] != -1 && start == -1) {
                start = i;
            }
            end = max(end, c[i]);
            if (end == i) {
                res.push_back({start, end});
                start = -1;
                end = -1;
            }
            cout << i << " " << start << " " << end << endl;
        }
        if (end != -1) res.push_back({start, end});
        return res;
    }
};
