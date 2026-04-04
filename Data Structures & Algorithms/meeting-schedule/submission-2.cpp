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
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {return x.start < y.start;});
        for (int i = 0; i < intervals.size(); ++i) {
            int j = i + 1;
            if (j < intervals.size() && intervals[j].start <  intervals[i].end) {
                return false;
            }
        }

        return true;
    }
};
