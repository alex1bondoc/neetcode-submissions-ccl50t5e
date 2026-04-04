class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res{};
        int i{};
        for(; i < intervals.size() && intervals[i][0] <= newInterval[0]; ++i) {
            if (intervals[i][1] >= newInterval[0]) {
                newInterval[0] = intervals[i][0];
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
                i += 1;
                while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
                    newInterval[1] = std::max(intervals[i][1], newInterval[1]);
                    i ++;
                }
                break;
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
                    newInterval[1] = std::max(intervals[i][1], newInterval[1]);
                    i ++;
                }
        res.push_back(newInterval);
        for(; i < intervals.size(); ++i) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
