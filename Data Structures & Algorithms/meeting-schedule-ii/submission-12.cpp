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
        vector<vector<int>> time;
        for (const auto& interval : intervals) {
            time.push_back({interval.start, 1});
            time.push_back({interval.end, -1});
        }
        sort(time.begin(), time.end());
        int c{}, res{};
        for (const auto& t : time) {
            c += t[1];
            res= max(c, res);

        }
        return res;
    }
};