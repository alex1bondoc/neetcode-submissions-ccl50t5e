class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size();) {
            int j = i + 1;
            while (j < intervals.size() && intervals[i][1] >= intervals[j][0]) {
                intervals[i][0] = std::min(intervals[j][0], intervals[i][0]);
                intervals[i][1] = std::max(intervals[i][1], intervals[j][1]);
                j ++;
            }
            res.push_back(intervals[i]);
            i = j;
        }
        return res;
    }
};
