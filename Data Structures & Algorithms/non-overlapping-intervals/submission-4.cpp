class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if (intervals.size() == 0) return 0;
        int prevEnd{intervals[0][1]}, res{};
        for (int i{1}; i < intervals.size(); ++i) {
            int start{intervals[i][0]};
            int end{intervals[i][1]};
            if (start < prevEnd) {
                res++;
                prevEnd = min(prevEnd, end);
            }
            else {
                prevEnd = end;
            }
        } 
        return res;
    }
};
