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
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){return x.end < y.end;} );
        int cnt = 1;
        Interval interval{intervals[0]};
        for(int i = 1; i < intervals.size(); ++i) {
            if (interval.end <= intervals[i].start){
                interval = intervals[i];
            }
            else {
                cnt ++;
            }
        }
        return cnt;
    }
};
