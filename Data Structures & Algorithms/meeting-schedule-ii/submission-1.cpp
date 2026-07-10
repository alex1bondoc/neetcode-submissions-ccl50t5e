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
        std::sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){return x.start < y.start;} );
        int cnt = 1;
        for(int i = 1; i < intervals.size(); ++i) {
            if (intervals[i-1].end < intervals[i].start){
                cnt ++;
            }
        }
        return cnt;
    }
};
