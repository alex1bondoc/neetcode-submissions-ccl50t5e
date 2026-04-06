class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int maxStart{};
        for (int i{}; i < intervals.size(); ++i) {
            if (intervals[i][0] >  maxStart) {
                maxStart = intervals[i][0];
            }
        } 
        std::vector<int> startToEnd(maxStart + 1);
        for (std::vector<int> interval : intervals) {
            startToEnd[interval[0]] = std::max(interval[1] + 1, startToEnd[interval[0]]);
        }
        std::vector<vector<int>> res{};
        int start = -1;
        int end = -1;
        for (int i = 0; i <= maxStart; ++i) {
            std::cout << i <<  " " << startToEnd[i] << endl;
            if (startToEnd[i] != 0) {
                std::cout << i << endl;
                if (start == -1) {
                    start = i;
                }
                end = std::max(end, startToEnd[i] - 1);
            }
            std::cout << end<< endl;
            if (i == end) {
                res.push_back({start, end});
                start = -1;
                end = -1;
            }
        }
        if (start != - 1) {
            res.push_back({start, end});
        }
        return res;
    }
};
