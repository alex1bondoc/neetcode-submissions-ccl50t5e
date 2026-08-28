class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxi{};
        for (const auto& i : intervals) {
            maxi = max(i[0], maxi);
        }
        vector<vector<int>> res;
        vector<int> match(maxi + 1, -1);
        for (const auto& i : intervals) {
            match[i[0]] = max(match[i[0]], i[1]);
        }
        int start{-1}, end{-1};
        for (int i{}; i <= maxi; ++i) {
            if (match[i] != -1 && start == -1) {
                start = i;
            }
            end = max(end, match[i]);
            if (i == end) {
                res.push_back({start, end});
                start = -1;
                end = -1;
            }
        }
        if (end != -1) res.push_back({start, end});
        return res;
    }
};
