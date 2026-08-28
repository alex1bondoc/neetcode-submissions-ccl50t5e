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
            return a.end == b.end ? a.start < b.start : a.end < b.end;
        });
        int start{};
        int end{};
        int res{}, count{};
        while (start < intervals.size() && end < intervals.size()) {
            if (intervals[start].start < intervals[end].end){
                count ++;
                start ++;
            }
            else {
                count --;
                end ++;
            }
            res = max(res, count);
        }
        return res;
    }
};
