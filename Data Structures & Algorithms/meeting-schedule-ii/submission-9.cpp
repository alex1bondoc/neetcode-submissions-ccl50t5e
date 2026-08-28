/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });
        int res{1};
        int prevEnd{intervals[0].end};
        for (int i{1}; i < intervals.size(); ++i) {
            int start{intervals[i].start};
            int end{intervals[i].end};
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
