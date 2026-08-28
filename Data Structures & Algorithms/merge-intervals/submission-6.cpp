class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n{static_cast<int>(intervals.size())};
        sort(intervals.begin(), intervals.end());
        int newStart{intervals[0][0]};
        int newEnd{intervals[0][1]};
        for (int i{1}; i < n; ++i) {
            if (intervals[i][0] <= newEnd) {
                newEnd = max(newEnd, intervals[i][1]);
            }
            else {
                res.push_back({newStart, newEnd});
                newStart = intervals[i][0];
                newEnd = intervals[i][1];
            }
        }
        res.push_back({newStart, newEnd});
        return res;
    }
};
