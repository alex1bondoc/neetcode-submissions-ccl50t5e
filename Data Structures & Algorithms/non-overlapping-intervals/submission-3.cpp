class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        int res = 1;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size() ;++i) {
            if (intervals[i][0] <  prevEnd) {
                prevEnd = std::min(prevEnd, intervals[i][1]);
            }
            else {
                res ++;
                prevEnd = intervals[i][1];
            }
        }
        return intervals.size() - res;
    }
};
