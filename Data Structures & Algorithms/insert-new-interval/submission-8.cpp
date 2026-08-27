class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n{static_cast<int>(intervals.size())};
        int last{-1};
        for (int i{}; i < n; ++i) {
            if (intervals[i][0] <= newInterval[0]) last = i;
        }
        if (last == -1) {
            intervals.insert(intervals.begin(), newInterval);
            last = 0;
        }
        else {
        auto interval{intervals[last]};
        if (newInterval[0] <= interval[1] && newInterval[1] <= interval[1]) {
            return intervals;
        }
        else if(newInterval[0] < interval[1] ) {
            intervals[last][1] = newInterval[1];
        }
        else {
            intervals.insert(intervals.begin() + last + 1, newInterval);
            last++;
        }
        }
        while (last < intervals.size() - 1 && intervals[last][1] >= intervals[last + 1][0]) {
            intervals[last][1] = max(intervals[last + 1][1], intervals[last][1]);
            intervals.erase(intervals.begin() + last + 1);
        }

        return intervals;
    }
};
