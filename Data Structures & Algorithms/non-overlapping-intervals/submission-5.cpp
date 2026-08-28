class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        if (intervals.size() == 0) return 0;
        int res{};
        int last{intervals[0][1]};
        for (int i{1}; i < intervals.size(); ++i) {
            int start{intervals[i][0]}, end{intervals[i][1]};
            if (last <= start) {
                last = end;
            }
            else {
                res++;
                last = min(last, end);
            }
        }
        return res;
    }
};
